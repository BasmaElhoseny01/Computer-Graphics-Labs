#version 330
// Defining OpenGL must be first line
//Vertex Shader

//Varyings(Sending from Vertex Shader to Fragment Shader)
out vec4 vertex_color;

//Attributes
layout (location=0) in vec3 position;
layout (location=1) in vec4 color;


//4.MVP Uniform
uniform mat4 MVP;

void main() {

    //Third Paramter for how near and far(depth)
    gl_Position = MVP*vec4(position, 1.0);
    //gl_Position = vec4(position, 1.0);

    //10.Vertex Color is an attribute read from the buffer
    vertex_color = color;
}
