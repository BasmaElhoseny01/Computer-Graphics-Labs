#include <iostream>
#include <string>
#include <fstream>

// Include GLAD
// Include before glfw bec glfw by default if it didn't find OpenGL it loads it so this new include throws error of redefinition
#include <glad/gl.h>

// Include glfw =>refer to CmakeList.txt to see config
#include <GLFW/glfw3.h>

using namespace std;

// 8.Create Load Shader Function ⛽
/*Define Function to shader we have just written for the triangle 📐📐 */
// So that we call this one for the vertex shader and another time for the fragment shader
GLuint load_shader(const std::string &path, GLenum shader_type)
{
    // Read Shader Source Code [Reading from files 🐥🐥]
    std::ifstream file(path);
    std::string sourceCode = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    const char *sourceCodeCStr = sourceCode.c_str();

    // Shader Type and Type is passed as an argument
    GLuint shader = glCreateShader(shader_type);
    // Source Code for this newly created Shader ?😜😜
    /*Shader ,no of shader strings to be added together, array of shaders to be integrated ,size of teh Shader Length but here it is  a string so the null operator will end this up(i.e i tell him you find the end of shader your self 🙄🙄)*/
    glShaderSource(shader, 1, &sourceCodeCStr, nullptr);
    glCompileShader(shader);

    // But What if the there is compilation error how will we know 🤔🤔🤔.
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status)
    {
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        char *logStr = new char(length);
        glGetShaderInfoLog(shader, length, nullptr, logStr);

        cerr << "Error in " << path << endl;
        cerr << logStr << endl;

        delete[] logStr;
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

int main()
{
    cout << "Hello from a shader";
    // Till Here it is fine we just type ctrl+f5 so that this is printed in the console
    // But we need A window to draw :( But we have a problem of opening window it differs from one OS to another
    // Sol: Get a library that is Cross Platform to be responsible for opening the window  ***[glfw]
    // Note:Take the Library and add here in folder called vendor (for organization of code)

    // Using GLFW to create the Window 😎
    // 1.Init GLFW
    /*Return int true =>successful false = error*/
    if (!glfwInit())
    {
        cerr << "Failed to initialize GLFW\n";
        cout << "error";
        exit(1); // To terminate :)
    }

    // 5.Version of OpenGl **********Must be before creating window 💥💣🧨
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // 2.Create Window
    //  (Size,Size,Window Name,Full screen,share Resources between different windows 🤗)
    GLFWwindow *window = glfwCreateWindow(600, 400, "Hello Window", nullptr, nullptr);
    if (!window)
    {
        cerr << "Failed to Create Window\n";
        glfwTerminate();
        exit(1);
    }

    // 6.Link Context we create to the window opened 🐣
    // ie what we write here to be shown on this window
    glfwMakeContextCurrent(window);

    // 4.Load GLAD
    /*gladLoadGL(Function to be used jn loading)*/
    /*Ex when we type glClearColor it return a pointer to this function in the driver 😲*/
    if (!gladLoadGL(glfwGetProcAddress))
    {
        cerr << "Failed to Load Open GL\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(1);
    }

    // 7.Clear Screen with a specific color
    // 7.1.Specify Color
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black

    // 9.Create 2 Shaders
    GLuint vs = load_shader("D:/Computer-Graphics-Labs/Lab1/assets/shaders/simple.vert", GL_VERTEX_SHADER);
    GLuint fs = load_shader("D:/Computer-Graphics-Labs/Lab1/assets/shaders/simple.frag", GL_FRAGMENT_SHADER);

    // GLuint vs = load_shader("assets/shaders/simple.vert", GL_VERTEX_SHADER);
    // GLuint fs = load_shader("assets/shaders/simple.frag", GL_FRAGMENT_SHADER);
    // To use Both Shaders together we need to combine them in a page ➕
    GLuint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    // Now 2 shaders are in the same pipeline 😁😁😁.

    // Now we no more need these 2 shaders we have already linked in so we can delete them 🧺🧺.
    // The program have took the data from them we no longer need theme 😎😎😎.
    glDeleteShader(vs);
    glDeleteShader(fs);

    // 10.Vertex Array [Used here else not working Wait for the next time to understand what does it do ⌚⌚⌛⏳]
    GLuint vertex_array;
    /**Count , array*/
    glGenVertexArrays(1, &vertex_array);

    // 3.While Loop
    //  glfwWindowShouldClose(..) true when we press on the x of the window 🤨
    while (!glfwWindowShouldClose(window))
    {
        // To make him see User Inputs and message queue 🤐
        glfwPollEvents();

        // 7.2.Execute this command
        glClear(GL_COLOR_BUFFER_BIT);

        // 11.Now we need to Draw
        glUseProgram(program);
        glBindVertexArray(vertex_array);
        /* Use Triangles , start from vertex 0 , draw 3 vertices*/
        glDrawArrays(GL_TRIANGLES, 0, 4);
        // glDrawArrays(GL_TRIANGLES, 0,6);//2 triangles are drawn :) 6 vertices

        // But this Command is executed in the back Buffer screen not front
        // 8.Call Swap to see the update 🥱
        glfwSwapBuffers(window);
    }

    // Delete Program
    glDeleteProgram(program);

    glfwDestroyWindow(window);
    glfwTerminate();
}

/*Note: Problem of ctrl f5 doesn't draw the Triangle The problem is jys a path problem 💣💣 where shaders path passed are relative anf f5 run from build so nothin gis found if you try to run .exe from the terminal where the paths are fine it works 😉*/
// Solution launch.json =>configure debug mode [But this works only in Debug]
// Solution add cwd in setings.json 😋😋

// Note : Creating bin file & telling him to add the .exe in it instead of build(default location that differs from one compiler to another 😢)
// Solution refer to the 3 lines in the CMakeLists.txt