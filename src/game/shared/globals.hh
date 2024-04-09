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
#ifndef SRC_GAME_SHARED_GLOBALS_HH
#define SRC_GAME_SHARED_GLOBALS_HH
#include <entt/entity/fwd.hpp>
#include <entt/signal/fwd.hpp>
#include <stdint.h>

namespace globals
{
extern float frametime;
extern uint64_t curtime;
extern uint64_t framecount;

extern entt::registry registry;
extern entt::dispatcher dispatcher;
} // namespace globals

#endif /* SRC_GAME_SHARED_GLOBALS_HH */
