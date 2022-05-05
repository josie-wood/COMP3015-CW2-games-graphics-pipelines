
#version 400 core

layout( location = 0 ) in vec3 vPosition;
layout( location = 1 ) in vec4 vColour;
uniform mat4 mvp;

uniform mat4 m;
uniform mat4 v;
uniform mat4 p;

in vec4 fColor;
out vec4 colourPass1;
void
main()
{
    gl_Position = m * vec4 (vPosition,1.0);
	//colourPass1 = vColour;
	colourPass1 = vec4(0.1, 0.2, 0.8, 1.0);;
}
