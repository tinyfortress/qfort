// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2022, Kirill GPRB
// Copyright (c) 2024, QFort Contributors
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
#include <client/main.hh>
#include <config/cmake.hh>
#include <config/limits.hh>
#include <filesystem>
#include <server/main.hh>
#include <shared/cmdline.hh>
#include <shared/vfstools.hh>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <stdlib.h>

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    cmdline::append(argc, argv);

    auto logger = spdlog::default_logger_raw();
    auto &sinks = logger->sinks();

    sinks.clear();
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("qfort.log", true));
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

    logger->set_level(spdlog::level::info);
    logger->set_pattern("[%H:%M:%S] %^[%L]%$ %v");

    if(cmdline::contains("debug"))
        logger->set_level(spdlog::level::debug);
    if(cmdline::contains("trace"))
        logger->set_level(spdlog::level::trace);

#if defined(QFORT_CLIENT)
    spdlog::info("QFort {} client {}", CMAKE_SYSTEM_NAME, QFORT_VERSION);
#elif defined(QFORT_SERVER)
    spdlog::info("QFort {} server {}", CMAKE_SYSTEM_NAME, QFORT_VERSION);
#endif

    if(!PHYSFS_init(argv[0])) {
        spdlog::critical("physfs: init failed: {}", vfstools::last_error());
        std::terminate();
    }

    std::error_code error = {};
    std::string gamedir_option = {};
    std::string gamedir_value = DEFAULT_GAMEDIR;

    if(cmdline::get("gamedir", gamedir_option))
        gamedir_value = gamedir_option;
    if(cmdline::get("game", gamedir_option))
        gamedir_value = gamedir_option;

    fs::path gamedir = fs::canonical(gamedir_value, error);

    if(error) {
        spdlog::critical("fs: canonical failed: {}: {}", gamedir_value, error.message());
        std::terminate();
    }

    spdlog::debug("fs: gamedir = [{}]", gamedir.string());
    spdlog::debug("fs: current_path = [{}]", fs::current_path().string());

    if(!PHYSFS_setWriteDir(gamedir.string().c_str())) {
        spdlog::critical("physfs: setwritedir failed: {}: {}", gamedir.string(), vfstools::last_error());
        std::terminate();
    }

    for(unsigned i = 1; i <= QFZIP_MAX; ++i) {
        const auto file = fmt::format("QF_{:03}.zip", i);
        const auto path = gamedir / file;

        if(PHYSFS_mount(path.string().c_str(), nullptr, false))
            continue;
        break;
    }

    if(!PHYSFS_mount(gamedir.string().c_str(), nullptr, false)) {
        spdlog::critical("physfs: mount failed: {}: {}", gamedir.string(), vfstools::last_error());
        std::terminate();
    }

#if defined(QFORT_CLIENT)
    client::main();
#elif defined(QFORT_SERVER)
    server::main();
#else
    #error Have your heard of the popular hit game Among Us?
    #error Its a really cool game where 1-3 imposters try to kill off the crewmates,
    #error while the crew has to finish their tasks or vote off the imposters to win.
    #error Its 5 dollars on Steam and consoles but it is free on App Store and Google Play.
#endif

    if(!PHYSFS_deinit()) {
        spdlog::critical("physfs: deinit failed: {}", vfstools::last_error());
        std::terminate();
    }

    return 0;
}
