#version 330 core

in vec3 vs_Position;
in vec2 vs_Texcoord;

out vec4 out_Color;

void main(void)
{
    out_Color.xy = vs_Texcoord;
    out_Color.z = 1.0;
    out_Color.w = 1.0;
}
