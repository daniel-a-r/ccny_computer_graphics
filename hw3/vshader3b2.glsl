#version 330

// PUT YOUR CODE HERE
in	vec3	a_Position;	// attribute variable: position vector

uniform mat4	u_View;	// uniform variable for modelview matrix
uniform mat4	u_Projection;	// uniform variable for projection matrix

void main() 
{
	// PUT YOUR CODE HERE
	gl_Position = u_Projection * u_View * vec4(a_Position, 1);
}
