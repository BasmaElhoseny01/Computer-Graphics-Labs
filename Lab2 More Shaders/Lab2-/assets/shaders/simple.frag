#version 330
// [VIP] The above line must be the first line even no comment can be before it
//Fragment Shader => Colro of each Pixel ❄

out vec4 frag_color;

//Take Vertices colors from vertex shader
in vec4 vertex_color;

void main() {
    //Take color of pixels from vertex shader 😎
    frag_color = vertex_color ;
}

//NB:Origin is @ Left Down of the screen
//Till width and height of the window 🌟
