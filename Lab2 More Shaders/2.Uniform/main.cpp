#include <iostream>
// Include before glfw bec glfw
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>

using namespace std;

GLuint load_shader(const std::string &path, GLenum shader_type)
{
    // Read Shader Source Code
    std::ifstream file(path);
    std::string sourceCode = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    const char *sourceCodeCStr = sourceCode.c_str();

    // Shader Type and Type is passed as an argument
    GLuint shader = glCreateShader(shader_type);
    // Source Code for this newly created Shader ?😜😜
    /*Shader ,.., array of shaders to be integrated ,size of teh Shader Length but here it is  a string so the null operator will end this up(i.e i tell him you find the end of shader your self 🙄🙄)*/
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
using namespace std;
int main()
{
    cout << "Hello from a shader";
    // Using GLFW to create the Window 😎
    // Init GLFW
    /*Return int true =>successful false = error*/
    if (!glfwInit())
    {
        cerr << "Failed to initialize GLFW\n";
        exit(1); // To terminate :)
    }

    // Version of OpenGl **********Must be before creating window 💥💣🧨
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Create Window
    //   (Size,Size,Window Name,Full screen,share Resources between different windows 🤗)
    GLFWwindow *window = glfwCreateWindow(600, 400, "Hello Window", nullptr, nullptr);
    if (!window)
    {
        cerr << "Failed to Create Window\n";
        glfwTerminate();
        exit(1);
    }

    // Link Context we create to the window opened 🐣
    //  ie what we write here to be shown on this window
    glfwMakeContextCurrent(window);

    // Load GLAD
    /*gladLoadGL(Function to be used jn loading)*/
    if (!gladLoadGL(glfwGetProcAddress))
    {
        cerr << "Failed to Load Open GL\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(1);
    }

    // Clear Screen with a specific color
    // Specify Color(for gb)
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black

    // Create 2 Shaders
    GLuint vs = load_shader("assets/shaders/simple.vert", GL_VERTEX_SHADER);
    GLuint fs = load_shader("assets/shaders/simple.frag", GL_FRAGMENT_SHADER);
    // To use Both Shaders together we need to combine them in a page ➕
    GLuint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    // Now 2 shaders are in the same pipeline 😁😁😁.

    // Delete shaders
    glDeleteShader(vs);
    glDeleteShader(fs);

    // Vertex Array
    GLuint vertex_array;
    /**Count , array*/
    glGenVertexArrays(1, &vertex_array);

    // 2.1.2.Getting uniform of the time uniform variable 😉
    //  (program, name of the uniform required[as defined in vertex shader :D])
    GLuint time_loc = glGetUniformLocation(program, "time");
    std::cout << "Time uniform location: " << time_loc << endl;

    // While Loop
    //  glfwWindowShouldClose(..) true when we press on the x of the window 🤨
    while (!glfwWindowShouldClose(window))
    {
        // 2.1.3 Getting time
        float time = (float)glfwGetTime();

        // To make him see User Inputs and message queue 🤐
        glfwPollEvents();

        // Execute this command
        glClear(GL_COLOR_BUFFER_BIT);

        // Now we need to Draw
        glUseProgram(program);
        glBindVertexArray(vertex_array);

        // 2.1.4 send the time to the time uniform😜 (location, value)
        glUniform1f(time_loc, time);

        /* Use Triangles , start from vertex 0 , draw 3 vertices*/
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // //Draw another one 😲 with same shaders.
        // glUniform1f(time_loc, time+10.0);
        // glDrawArrays(GL_TRIANGLES, 0, 3);

        // But this Command is executed in the back Buffer screen not front
        // Call Swap to see th update 🥱
        glfwSwapBuffers(window);
    }

    // Delete Program
    glDeleteProgram(program);

    glfwDestroyWindow(window);
    glfwTerminate();
}