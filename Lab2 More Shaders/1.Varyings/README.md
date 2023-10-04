# Varying
### Vertex Shader sends Data(color) to Fragment Shader

## <img align= center width=50px height=50px src="https://thumbs.gfycat.com/UnhappyJubilantLaughingthrush-size_restricted.gif"> Code Map
1. Varying
    - define array of 3 colors <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/1.Varyings/assets/shaders/simple.vert#L16-L20">here</a>
    - define color for the vertex out from vertex shader<a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/1.Varyings/assets/shaders/simple.vert#L7">here</a>
    ```
    out vec4 vertex_color;
    ```
    - assign out to the corresponding color <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/1.Varyings/assets/shaders/simple.vert#L24-L25">here</a>
    ```
    vertex_color = colors[gl_VertexID];
    ```
    - Vertex color is an input to fragment shader <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/1.Varyings/assets/shaders/simple.frag#L7-L8">here</a>
    ```
    in vec4 vertex_color;
    ```
    - assign gl_color to the input in fragment shader
    ```
    frag_color = vertex_color ;
    ```
    - Run Program Note Effect of interpolation 😳.


## <img align= center width=50px height=50px src="https://mir-s3-cdn-cf.behance.net/project_modules/disp/d4156f91706591.5e3906ec9acf9.gif"> Notes
- Note that here we have defined triangle completely from vertex shader so we have 3 vertices with three positions & colors so for the fragment  shader what is the color for the rest of the vertices ❓❓ Interpolation takes place by the rasterizer

- Modifying shader files no need to compile again bec .cpp is unmodified