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
#include <shared/globals.hh>
#include <entt/entity/registry.hpp>
#include <entt/signal/dispatcher.hpp>

float globals::frametime = 0.0;
uint64_t globals::curtime = 0U;
uint64_t globals::framecount = 0U;

entt::registry globals::registry = {};
entt::dispatcher globals::dispatcher = {};
