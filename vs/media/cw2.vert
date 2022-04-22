
#version 400 core

layout( location = 0 ) in vec3 vPosition;
layout( location = 1 ) in vec4 vColour;
uniform mat4 mvp;

in vec4 fColor;
out vec4 colourPass1;
void
main()
{
    gl_Position = mvp * vec4 (vPosition,1.0);
	//colourPass1 = vColour;
	colourPass1 = vec4(0.1, 0.2, 0.8, 1.0);;
}
