// SPDX-License-Identifier: GPL-2.0-only
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
#ifndef CONFIG_CMAKE_HH
#define CONFIG_CMAKE_HH

constexpr static const char *CMAKE_CXX_COMPILER_ID = "GNU";

constexpr static const char *CMAKE_SYSTEM = "Linux-6.8.4-arch1-1";
constexpr static const char *CMAKE_SYSTEM_NAME = "Linux";
constexpr static const char *CMAKE_SYSTEM_PROCESSOR = "x86_64";
constexpr static const char *CMAKE_SYSTEM_VERSION = "6.8.4-arch1-1";

constexpr static unsigned CMAKE_VERSION_MAJOR = 3;
constexpr static unsigned CMAKE_VERSION_MINOR = 29;
constexpr static unsigned CMAKE_VERSION_PATCH = 1;
constexpr static unsigned CMAKE_VERSION_TWEAK = 0;
constexpr static const char *CMAKE_VERSION = "3.29.1";

constexpr static unsigned QFORT_VERSION_MAJOR = 0;
constexpr static unsigned QFORT_VERSION_MINOR = 0;
constexpr static unsigned QFORT_VERSION_PATCH = 1;
constexpr static const char *QFORT_VERSION = "0.0.1";

constexpr static const char *DEFAULT_GAMEDIR = "tfort";

#endif /* CONFIG_CMAKE_HH */
