#version 330
// [VIP] The above line must be the first line even no comment can be before it
//Fragment Shader => Colro of each Pixel ❄

out vec4 frag_color;

//Take Vertices colors from vertex shader
// in vec4 vertex_color;

in Varyings{
    vec4 color;
    vec2 tex_coord;
} fs_in;



// Texel data is taken from main so it is uniform
uniform sampler2D tex; 

void main() {
    //Take color of pixels from vertex shader 😎
    // frag_color = vertex_color ;
    
    // Lab(4):Texture  Step(2)
    // gvec4 texelFetch(gsampler2D sampler, ivec2 P,int lod); 
    //p:coordinates at which th texture will be sampled ivec2 integer vector 2
    // frag_color=texelFetch(tex,ivec2(gl_FragCoord),0);[Acess pixel by pixel]
    frag_color=texture(tex,ivec2(fs_in.tex_coord));//to add the tex_coord

}

//NB:Origin is @ Left Down of the screen
//Till width and height of the window 🌟
