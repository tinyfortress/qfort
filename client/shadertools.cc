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
#include <client/shadertools.hh>
#include <shared/strtools.hh>
#include <shared/vfstools.hh>
#include <spdlog/spdlog.h>
#include <sstream>

static void print_info_log(GLuint object, const std::string &info)
{
    std::string line = {};
    std::istringstream stream = std::istringstream{info};

    while(std::getline(stream, line)) {
        if(line[0] == 0x00)
            continue;
        if(strtools::is_empty_or_whitespace(line))
            continue;
        spdlog::debug("shadertools: [{}]: {}", object, line);
    }
}

static bool check_shader(GLuint shader)
{
    int status, info_size;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_size);

    if(info_size >= 2) {
        std::string info = {};
        info.resize(info_size);
        glGetShaderInfoLog(shader, info.size(), nullptr, info.data());
        print_info_log(shader, info);
    }

    return status;
}

static bool check_program(GLuint program)
{
    int status, info_size;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_size);

    if(info_size >= 2) {
        std::string info = {};
        info.resize(info_size);
        glGetProgramInfoLog(program, info.size(), nullptr, info.data());
        print_info_log(program, info);
    }

    return status;
}

GLuint shadertools::from_file(GLenum type, const std::string &path)
{
    std::string source;
    if(vfstools::read_file(path, source))
        return shadertools::from_source(type, source);
    spdlog::warn("shadertools: {}: {}", path, vfstools::last_error());
    return 0;
}

GLuint shadertools::from_source(GLenum type, const std::string &source)
{
    auto source_cstr = source.c_str();
    auto shader = glCreateShader(type);

    glShaderSource(shader, 1, &source_cstr, nullptr);
    glCompileShader(shader);

    if(check_shader(shader))
        return shader;
    
    glDeleteShader(shader);
    return 0;
}

GLuint shadertools::link_program(const std::vector<GLuint> &shaders)
{
    auto program = glCreateProgram();

    for(auto shader : shaders)
        glAttachShader(program, shader);
    glLinkProgram(program);

    if(check_program(program))
        return program;
    
    glDeleteProgram(program);
    return 0;
}
