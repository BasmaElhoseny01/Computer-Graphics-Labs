#version 330
// Defining OpenGL must be first line
//Vertex Shader



//Attributes IN FROM MAIN
layout (location=0) in vec3 position;
layout (location=1) in vec4 color;
layout (location=2) in vec2 tex_coord;

// OUT TO FRAGMENT SHADER
//Varyings(Sending from Vertex Shader to Fragment Shader)
out Varyings{
    vec4 color;
    vec2 tex_coord;
} vs_out;


//4.MVP Uniform
uniform mat4 MVP;

void main() {

    //Third Paramter for how near and far(depth)
    gl_Position = MVP*vec4(position, 1.0);
    //gl_Position = vec4(position, 1.0);

    //10.Vertex Color is an attribute read from the buffer
    vs_out.color =color;
    vs_out.tex_coord=tex_coord;
}
