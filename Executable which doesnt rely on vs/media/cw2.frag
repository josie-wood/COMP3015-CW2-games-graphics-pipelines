#version 450 core

in vec4 fragColourPass;
out vec4 fColor;


uniform sampler2D ourTexture;

void main()
{
    fColor = fragColourPass;
	//vec4(0.0, 0.4, 0.0, 1.0);
	//fColor = texture(ourTexture, TexCoordPass) * fragColourPass;
	
}
