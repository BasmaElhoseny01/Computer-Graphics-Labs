#version 330
// Defining OpenGL must be first line
//Vertex Shader

//1.Varyings :Sending from Vertex Shader to Fragment Shader
//1.2 Out it
out vec4 vertex_color;

void main() {

    vec3 positions[3] = vec3[3](
        vec3(-0.5, -0.5, 0.0),
        vec3(0.5, -0.5, 0.0),
        vec3(0.0, 0.5, 0.0));

    //1.1 Colors for the Three Vertices send it to Fragment Shader
    const vec4 colors[3] = vec4[3](
        vec4(1.0, 0.0, 0.0, 1.0),//r
        vec4(0.0, 1.0, 0.0, 1.0),//g
        vec4(0.0, 0.0, 1.0, 1.0));//b

    gl_Position = vec4(positions[gl_VertexID],1.0);

    //1.2 Give Each vertex its color
    vertex_color = colors[gl_VertexID];
}
