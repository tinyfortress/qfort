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
#ifndef CLIENT_SHADERTOOLS_HH
#define CLIENT_SHADERTOOLS_HH
#include <glad/gl.h>
#include <string>
#include <vector>

namespace shadertools
{
GLuint from_file(GLenum type, const std::string &path);
GLuint from_source(GLenum type, const std::string &source);
GLuint link_program(const std::vector<GLuint> &shaders);
} // namespace shadertools

#endif /* CLIENT_SHADERTOOLS_HH */
