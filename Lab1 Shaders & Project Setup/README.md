## Overview
We will write C++ with OpenGL and write our first Shader on the screen 

But in the Last Section we draw a shader but did we write the code that load this shader and run it ? No we used ShaderToy
 
## First Configuration
1. ctrl+shift+P
2. Cmake Quick Start
3. Choose Compiler
4. Project name
5. Executable
6. Build and Run
```
ctrl + f5 = build + run   ==>.exe is created with name of the project 🤩
```

#### Till here we what we have just did is to run a simple .cpp program ex hello world but we made configuration by cmake :D

## Cmake File
Modify in the <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a4fc7ecc2c331fe5759bb529c6e7ba945285e92a/Lab1/CMakeLists.txt">CmakeList.txt</a> to remove unwanted commands

Check #[Required] Tag to search for the Basic 3 commands for this Step (Cmake Version - Project Version - Adding Executable)


## Pipeline
<img width="605" alt="Pipeline" src="https://user-images.githubusercontent.com/72309546/226156976-75faf395-1001-4313-8e27-c391382ee9c3.png">


### Vertex Data
In this lab we won't have this Vertex data sent of of the shader so we will place it hardcoded 👩‍💻 and next Lab send it from outside the shader 😳😳
### Vertex Shader
It takes Raw vertices Data and Calculate their positions on the screen
i.e Calculates the position of each pixel

```
📒 Note
NB:In Last Lab Vertex Shader was called on all pixels on the screen here it is Called on for the vertices foring the Shape 😊😊
```

### Rasterization
Get pixels(area) that the shape cover 📐📐 [out of points assembled]

### Fragment Shader
Calculates the color of each pixel

📒 Note
``` 
what we can program are both Vertex and Fragment Shaders but like Primitive assembler we only can change some configurations for it but not program it 😟.
```


## <img align= center width=50px height=50px src="https://thumbs.gfycat.com/UnhappyJubilantLaughingthrush-size_restricted.gif"> Code Map


1. GLFW 📚(Cross Platform to open the window) [Note it used Cmake 😲]
    - Add library to vendors folder 😛
    - Add this Library(project of another person) to the project <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/CMakeLists.txt#L18">ln 18 add_subdirectory</a>
    - 🔥 Error is thrown in CMakeLists.txt of glfw because folder tests and examples aren't found 🚫 OF COURSE WE WON'T MODIFY HIS CMakeLists.txt  <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/CMakeLists.txt#L11-L16">sol</a>
    
        💡 Add lines linked above to your Cmake to disable Testing and building
    - 😢 #include &lt;glfw&gt; Still Not seen 🎇 Make him know how to find out things in it <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/CMakeLists.txt#L23">include_directories</a>
    - 😊 #include &lt;GLFW/glfw3.h&gt; is seen 👀
    - still there is a problem => Change configuration Provider to CMake Tools
    - We need to tell him Build this library and link to our project <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/CMakeLists.txt#L39">target_link_libraries</a> 
    - 🥱🥱 Initialize and Terminate glfw  <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L63-L68">glfwInit()</a> & <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L149">glfwTerminate()</a>
    - Version of GLFW to be used <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L71-L72">glfwWindowHint</a>
    - Context for the Window Created <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L86">glfwMakeContextCurrent(window);</a>

2. Create Window <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L76">glfwCreateWindow()</a> & Destroy it @ end <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L148">glfwDestroyWindow()</a>
3. <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L123-L143">While loop</a> for the window to still open
4. GLAD 📚(Loader for OpenGL Functions) [Note it didn't use Cmake 😲 Just .h and .cpp files 📁]
    [It is like an interface between what we type and the functions of OpenGl in the driver]
    - Add library to vendors folder 😛
    - Add includes folder to <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/CMakeLists.txt#L22-L25">include_directories</a>
    - 🏗 Build This Library <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/CMakeLists.txt#L38">add_executable</a> 
    - 🥱🥱 Load GLAD <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L91-L97">gladLoadGL()</a>
5. Clear screen with a specific color
    - set color <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L101">glClearColor()</a>
    - Execute command of clearing with the color specified above :D <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L131">glClear()</a> [Won't work 😭😭].
    - Cleared screen hasn't been displauyed yet else it is in the back buffer 
        💡 swap buffers :👓<a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L142">glfwSwapBuffers()</a>
6. Vertex Shader
    - <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/assets/shaders/simple.vert#L1">Define gls version</a> MUST BE FIRST LINE
    - <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/assets/shaders/simple.vert#L20">gl_Position</a>

7. Fragment Shader
    - <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/assets/shaders/simple.frag#L1">Define gls version</a> MUST BE FIRST LINE
    - <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/assets/shaders/simple.frag#L11">frag_color</a> is an out instead of  fragColor used in Lab0 .glsl 🈴

        Till Here we have Created Shader But not Loaded Yet 😢

8. Load Shaders 🔮
    - create <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L17">load_shader()</a> to prevent code repeatability so used to load any shader 😲
    - Read Shader Source Code [Reading from files 🐥🐥] <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L19-L22">3 lines Here</a>
    - Create Shader
        - create shader object <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L25">glCreateShader()</a>
        - Pass Shader code to the shader object created <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L28">glShaderSource()</a>
        - Compile shader <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L29">glCompileShader()</a>
        - Add Codes to print error <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L31-L47">here</a> [Check on Shader Status]
    - Finally, Create the 2 shaders <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L103-L111">here</a> Note Program used to be able to use both 2 shaders together
    - Delete 2 Shaders [not used again already added to program] <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L115-L116">glDeleteShader()</a>
    - Delete Program before glfwTerminate() <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L146">glDeleteProgram()</a>

9. Create Vertex Array to Finally be Able to see our Program
    In next Lab we will understand it 😜[It is a must here to be able to run]<a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/main.cpp#L133-L138">code</a>
10. Run .exe but ctrl+fn+f5 not working [black screen instead] 
    
    💡 Run

    ```
    .\build\first_shader.exe
    ```
    💡 Solved in <a href="">Extra Configuration</a>
    
## ⚙️ Extra Configuration
Problem is that this line is relative to root directory but ctrl+fn+f5 calls .exe inside it so this path doesn't occur ie empty shader is read 🚿
```
    GLuint vs = load_shader("assets/shaders/simple.vert", GL_VERTEX_SHADER);
```

### 🔦 Debug Solution in <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/.vscode/launch.json">Launch.json</a> [This solves run from Debug]
    - ctrl+space=> windows launch for autocomplete
    - <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/.vscode/launch.json#L11"> program</a>
    - <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/.vscode/launch.json#L14"> cwd</a>
### 🔦 ctrl+fn+f5 Solution in <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/.vscode/settings.json#L1">Settings.json</a>
Add these line
```
    "cmake.debugConfig": {
        "cwd":"${workspaceFolder}"
    }
```


### Bin folder for .exe
in <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/CMakeLists.txt">CMakeLists.txt</a>
add these <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/a1e8d2f8b0981ac980796e13b5609652ff15a77a/Lab1/CMakeLists.txt#L28-L31">lines</a>
```
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)
```
## 🎉 UseFul Functions
- glfwGetTime()
