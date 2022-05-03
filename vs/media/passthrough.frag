#version 450 core

in vec4 colourPass1;
out vec4 fColor;


uniform sampler2D ourTexture;

void main()
{
    fColor = colourPass1;
	//vec4(0.0, 0.4, 0.0, 1.0);
	//fColor = texture(ourTexture, TexCoordPass) * fragColourPass;
	
}