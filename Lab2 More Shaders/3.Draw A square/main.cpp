#include <iostream>

// Include GLAD
// Include before glfw
#include <glad/gl.h>
// Include glfw =>refer to CmakeList.txt to see config
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>

using namespace std;

// 14. Define Structs
struct Position
{
    float x, y, z;
};

struct Color
{
    uint8_t r, g, b, a; // 1 byte
};

struct Vertex
{
    Position position;
    Color color;
};
// Create Shader Function ⛽
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
    // Specify Color (bg)
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

    // Delete Shaders
    glDeleteShader(vs);
    glDeleteShader(fs);

    // Update postion array to be array of Vertex
    // Vertex positions[6] = {
    //     {{0.5, 0.5, 0.0}, {0, 255, 0, 255}},
    //     {{0.5, -0.5, 0.0}, {0, 255, 255, 255}},
    //     {{-0.5, 0.5, 0.0}, {255, 255, 0, 255}},

    //     {{0.5, -0.5, 0.0}, {0, 255, 255, 255}}, // Common
    //     {{-0.5, 0.5, 0.0}, {255, 255, 0, 255}}, // Common
    //     {{-0.5, -0.5, 0.0}, {255, 0, 0, 255}}};

    // 2.1
    Vertex positions[4] = {
        {{0.5, 0.5, 0.0}, {0, 255, 0, 255}},
        {{0.5, -0.5, 0.0}, {0, 255, 255, 255}}, // common
        {{-0.5, 0.5, 0.0}, {255, 255, 0, 255}}, // common
        {{-0.5, -0.5, 0.0}, {255, 0, 0, 255}}};

    // 2.2 Define elements
    uint16_t elements[6] = {0, 1, 2, 3, 1, 2};

    // Past sol always sent by each frame from CPU to GPU
    //  💡 Sol: we need space in GPU to store this Data in GPU [Buffer]
    // Create Buffer
    GLuint vertex_buffer;
    /*count,pointer to vertex buffer*/
    glCreateBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer); // use GL_ARRAY_BUFFER to access this vertex_buffer
    // glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), positions, GL_STREAM_DRAW);
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), positions, GL_STREAM_DRAW);

    // 2.3 Define element Buffer
    GLuint element_buffer;
    /*count,pointer to element buffer*/
    glCreateBuffers(1, &element_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint16_t), elements, GL_STREAM_DRAW);

    // Use Data [Vertex Buffer]
    // Till here We have added Data inside buffer we need to read from it
    // But the problem is that the buffer just have data stored inside it he don't know what it is or even how to use it as partitions
    //  Vertex Array [How will we read these data from buffer]
    GLuint vertex_array;
    /**Count , array*/
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array); // bind vertex array to use it below

    // Setting position attribute value from the buffer :D
    // Getting pointer to this attribute
    /*(program, name of the attribute required)*/
    GLuint position_loc = 0;                 // Layout
    glEnableVertexAttribArray(position_loc); // enable vertex array to take data from

    // How to read position from vertex
    glVertexAttribPointer(position_loc, 3, GL_FLOAT, false, sizeof(Vertex), 0);

    // Setting color attribute Value
    // get Location
    GLuint color_loc = 1; // Layout
    // enable
    glEnableVertexAttribArray(color_loc);

    // How to read color from vertex
    /// offset (void*)(3*sizeof(float)) is still valid but this is a better way
    // Note here we made normalized true be color as we defined above is from 0-255 else the o/p is white :D
    glVertexAttribPointer(color_loc, 4, GL_UNSIGNED_BYTE, true, sizeof(Vertex), (void *)(offsetof(Vertex, color)));

    //To be Asked @BasmaElhoseny01
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
    
    // While Loop
    //  glfwWindowShouldClose(..) true when we press on the x of the window 🤨
    while (!glfwWindowShouldClose(window))
    {
        // To make him see User Inputs and message queue 🤐
        glfwPollEvents();

        // Execute this command
        glClear(GL_COLOR_BUFFER_BIT);

        // Now we need to Draw
        glUseProgram(program);
        glBindVertexArray(vertex_array);

        /* Use Triangles , start from vertex 0 , draw 6 vertices*/
        // triangle,cout,type which is that of element ,offset
        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void *)0);

        // But this Command is executed in the back Buffer screen not front
        // Call Swap to see th update 🥱
        glfwSwapBuffers(window);
    }

    // Delete Program
    glDeleteProgram(program);

    glfwDestroyWindow(window);
    glfwTerminate();
}