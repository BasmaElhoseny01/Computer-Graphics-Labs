#version 330
// [VIP] The above line must be the first line even no comment can be before it
//Fragment Shader => Colro of each Pixel ❄

out vec4 frag_color;

// 2.2.1Uniform :Sending from c++ to shaders 📫📫
uniform float time;

//1.4 Take Vertice color from vertex shader
in vec4 vertex_color;

void main() {

    // Multiply Color with sine of time so that it takes values from -1,1 
    //* Value taken from vertex shader
    frag_color = vertex_color * sin(10.0 * time);

    // Creating different phase for each channel sothe trigger not in phase
    // Using time uniform
    // vec4 tint = vec4(sin(10.0*time),sin(10.0*time+10.0),sin(10.0*time+20.0),1.0);
    // frag_color = vertex_color * tint;

    //Note sin from -1,1 ==> to make from 0-1
    // vec4 tint = vec4(sin(10.0*time),sin(10.0*time+10.0),sin(10.0*time+20.0),1.0);
    // tint=0.5*tint+0.5; //you find out that the time of black is now less ⏲⏲
    // frag_color = vertex_color * tint;

}

//NB:Origin is @ Left Down of the screen
//Till width and height of the window 🌟