#version 330
// Defining OpenGL must be first line
//Vertex Shader

//1.Varyings :Sending from Vertex Shader to Fragment Shader
//1.2 Out it
out vec4 vertex_color;

// 2.1.Define Uniform :Sending from c++ to shaders 📫📫
uniform float time;

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

    //2.1.1.Change x-direction postion of the vertices by sine wave for time
    //Here he used uniform value sent from the c++ 👨‍💻
    gl_Position = vec4(positions[gl_VertexID]+vec3(sin(time),0.0,0.0), 1.0);

    //1.2 Give Each vertex its color
    vertex_color = colors[gl_VertexID];
}
//NB:Origin is @ center of the screen
//From -1,-1 @ left bottom till 1,1 @ top right 😐 