# Uniform
### Send Data from c++ code to shaders
1. Send to the Vertex shaders the position of triangle 📐vertices
2. Send to the Fragment shaders the Colors 🎨🎨 pixels

## <img align= center width=50px height=50px src="https://thumbs.gfycat.com/UnhappyJubilantLaughingthrush-size_restricted.gif"> Code Map
1. Send time uniform from <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/main.cpp">main.cpp</a> to <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/assets/shaders/simple.vert">vertex shader</a>
    - Define uniform in vertex shader <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/assets/shaders/simple.vert#L10">here</a>
        ```
        uniform float time;
        ```
    - use this uniform to set gl_Position <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/assets/shaders/simple.vert#L27">here</a>
    - Before we assign value to time uniform in the <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/main.cpp">main.cpp</a> we need to get it from memory use <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/main.cpp#L110-L111">glGetUniformLocation()</a>
    - assign value to the time uniform <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/main.cpp#L131">glUniform1f()</a> [of Course inside loop 😆]
    - ctrl+fn+f5 🎁 now you find the triangle moving in x-direction
2. Send time uniform from main.cpp to fragment shader [Similar to vertex shader]
    -  Define uniform in vertex shader <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/assets/shaders/simple.frag#L8">here</a>
        ```
        uniform float time;
        ```
    - Use this time to set frag_color <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/assets/shaders/simple.frag#L17">here</a>
    - other options using time <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/assets/shaders/simple.frag#L19-L22">different phase</a>

## <img align= center width=50px height=50px src="https://mir-s3-cdn-cf.behance.net/project_modules/disp/d4156f91706591.5e3906ec9acf9.gif"> Notes

## 🎉 UseFul Functions
- <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/3120a28475d5bed99dd78cc7d47732ea5bbc844d/Lab2/2.Uniform/main.cpp#L118">glfwGetTime()</a>
