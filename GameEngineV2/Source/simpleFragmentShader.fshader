#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;

// Ouput data
out vec3 color;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;

void main(){
	vec2 updatedUV = vec2(UV.x, 1.0 - UV.y);
	// Output color = color of the texture at the specified UV
	color = texture( myTextureSampler, updatedUV ).rgb;
}