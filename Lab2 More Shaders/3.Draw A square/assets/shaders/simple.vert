#version 330
// Defining OpenGL must be first line
//Vertex Shader

//1.Varyings :Sending from Vertex Shader to Fragment Shader
//1.2 Out it
out vec4 vertex_color;

//position Attribute
layout (location=0) in vec3 position;
//9.Color attribute
layout (location=1) in vec4 color;


void main() {

    //Third Paramter for how near and far(depth)
    gl_Position = vec4(position, 1.0);

    //10.Vertex Color is an attribute read from the buffer
    vertex_color = color;
}
