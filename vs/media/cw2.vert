
#version 400 core

layout( location = 0 ) in vec3 vPosition;
layout( location = 1 ) in vec4 vColour;
uniform mat4 mvp;

in vec4 fColor;
out vec4 colour;
void
main()
{
    gl_Position = mvp * vec4 (vPosition,1.0);
	colour = vColour;
}
