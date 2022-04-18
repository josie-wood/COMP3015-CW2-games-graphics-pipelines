#version 450 core

out vec4 fColor;
in vec4 colour;

uniform sampler2D ourTexture;

void main()
{
    fColor = vec4(0.1, 0.2, 0.8, 1.0);
	//vec4(0.0, 0.4, 0.0, 1.0);
	//fColor = texture(ourTexture, TexCoordPass) * fragColourPass;
	
}
