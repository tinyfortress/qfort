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
#include <core/cmdline.hh>
#include <core/limits.hh>
#include <core/vfstools.hh>
#include <filesystem>
#include <server/main.hh>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <stdlib.h>

// UNDONE: make this a cmake option so game-specific
// forks of the engine will use a different default gamedir
constexpr static const char *DEFAULT_GAMEDIR = "tfort";

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

    if(!PHYSFS_init(argv[0])) {
        spdlog::critical("physfs: init failed: {}", vfstools::last_error());
        std::terminate();
    }

    std::string gamedir_argument = {};
    std::filesystem::path gamedir = DEFAULT_GAMEDIR;

    if(cmdline::get("game", gamedir_argument)) {
        gamedir = gamedir_argument;
    }

    if(gamedir.is_relative()) {
        // Dealing with absolute paths is better
        // in terms of reading console logs and seeing
        // exactly what location was the game running
        gamedir = std::filesystem::absolute(gamedir);
    }

    spdlog::debug("filesystem: cwd is {}", std::filesystem::current_path().string());
    spdlog::debug("filesystem: gamedir is {}", gamedir.string());

    if(!PHYSFS_setWriteDir(gamedir.string().c_str())) {
        spdlog::critical("physfs: setwritedir failed: {}: {}", gamedir.string(), vfstools::last_error());
        std::terminate();
    }

    for(unsigned i = 0; i < WFZIP_MAX; ++i) {
        const auto file = fmt::format("WF_{:03}.zip", i);
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
