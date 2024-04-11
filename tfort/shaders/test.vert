#version 330 core

in vec3 in_Position;
in vec2 in_Texcoord;
in vec3 in_Normal;

out vec3 vs_Position;
out vec2 vs_Texcoord;

void main(void)
{
    vs_Position = in_Position;
    vs_Texcoord = in_Texcoord;
    gl_Position.xyz = in_Position;
    gl_Position.w = 1.0;
}
