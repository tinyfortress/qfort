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
#ifndef CLIENT_EVENT_GLFW_MOUSE_BUTTON_HH
#define CLIENT_EVENT_GLFW_MOUSE_BUTTON_HH
#include <GLFW/glfw3.h>

struct GlfwMouseButtonEvent final {
    int button {GLFW_KEY_UNKNOWN};
    int action {};
    int mods {};
};

#endif /* CLIENT_EVENT_GLFW_MOUSE_BUTTON_HH */
