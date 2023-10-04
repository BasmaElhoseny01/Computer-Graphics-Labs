#version 330
// [VIP] The above line must be the first line even no comment can be before it
//Vertex Shader =>Postion of each vertex 😋
// Define OpenGL Version

void main(){
    //Define Three Vertecies
    vec3 positions[6] = vec3[6](
        //x,y,z
        vec3(-0.5,-0.5,0.0),
        vec3(0.5,-0.5,0.0),
        vec3(0.0,0.5,0.0),
        
        vec3(-1,-1,0.0),
        vec3(0.2,-1,0.0),
        vec3(-1,0.2,0.0)
    );

    //Fourth Parameter here (1.0) wait till Lab of Transformation ⌛⌛
    gl_Position=vec4(positions[gl_VertexID],1.0);
}

//NB:Origin is @ center of the screen
//From -1,-1 @ left bottom till 1,1 @ top right 😐  

// NB:In Last Lab Vertex Shader was called on all pixels on the screen here it is Called on for the vertices foring the Shape 😊😊
//Checkkk ??Vertex Shader is Called 3 times bec we have 3 vertices 