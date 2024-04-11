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
#include <client/game.hh>
#include <client/mesh.hh>
#include <client/shadertools.hh>
#include <exception>

static GLuint test_program = {};
static Mesh test_mesh = {};

void client_game::init(void)
{
    auto vert = shadertools::from_file(GL_VERTEX_SHADER, "shaders/test.vert");
    auto frag = shadertools::from_file(GL_FRAGMENT_SHADER, "shaders/test.frag");

    if(!vert || !frag)
        std::terminate();
    test_program = shadertools::link_program({vert, frag});

    if(!test_program)
        std::terminate();
    glDeleteShader(frag);
    glDeleteShader(vert);

    glBindAttribLocation(test_program, 0, "in_Position");
    glBindAttribLocation(test_program, 1, "in_Texcoord");
    glBindAttribLocation(test_program, 2, "in_Normal");

    glBindFragDataLocation(test_program, 0, "out_Color");

    std::vector<Vertex> vertices = {};
    vertices.push_back({{-0.5, -0.5, 0.0}, {0.0, 0.0}, {}});
    vertices.push_back({{+0.0, +0.5, 0.0}, {0.5, 1.0}, {}});
    vertices.push_back({{+0.5, -0.5, 0.0}, {1.0, 0.0}, {}});

    Mesh::create(test_mesh);
    Mesh::set(test_mesh, vertices);
}

void client_game::init_late(void)
{

}

void client_game::shutdown(void)
{
    Mesh::destroy(test_mesh);
    glDeleteProgram(test_program);
}

void client_game::update(void)
{

}

void client_game::update_late(void)
{

}

void client_game::render(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(test_mesh.vao);
    glUseProgram(test_program);
    glDrawArrays(GL_TRIANGLES, 0, test_mesh.size);
}
