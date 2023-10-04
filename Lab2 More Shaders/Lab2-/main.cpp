#include <iostream>

#include <glad/gl.h> //Note: Include GLAD before glfw
#include <GLFW/glfw3.h>

// 1.ii Add glm include
#include <glm/glm.hpp>
// 3.Use Library of Matrices in glm
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <fstream>

using namespace std;


struct Color
{
    uint8_t r, g, b, a; // 1 byte 8bits
};

struct Vertex
{
    glm::vec3 position; // Note her used glm:: bec we already have vec3 ad vec4 but he just wanted to show us that in the glm there is vector 4
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

    // 8.2.Clear Depth Buffer by this value
    glClearDepth(1.0f);//all set 1 

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

    Vertex positions[4] = {//This is now on the CPU RAM
        {{0.5, 0.5, 0.0}, {0, 255, 0, 255}},
        {{0.5, -0.5, 0.0}, {0, 255, 255, 255}}, // common
        {{-0.5, 0.5, 0.0}, {255, 255, 0, 255}}, // common
        {{-0.5, -0.5, 0.0}, {255, 0, 0, 255}}};

    // Define elements  //Defined on the CPU [RAM]
    uint16_t elements[6] = {0, 1, 2, 3, 1, 2};

    // Past sol always sent by each frame from CPU to GPU
    //  💡 Sol: we need space in GPU to store this Data in GPU [Buffer]
    // Create Buffer
    GLuint vertex_buffer;
    /*count,pointer to vertex buffer*/
    glCreateBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer); // use GL_ARRAY_BUFFER to access this vertex_buffer
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), positions, GL_STREAM_DRAW);//Add Data to the above bounded GL_ARRAY_BUFFER

    // Define element Buffer
    GLuint element_buffer;
    /*count,pointer to element buffer*/
    glCreateBuffers(1, &element_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint16_t), elements, GL_STREAM_DRAW);//Add Data to the above bounded GL_ELEMENT_ARRAY_BUFFER

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

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);

    // 6. MVP Uniform
    GLuint MVP_loc = glGetUniformLocation(program, "MVP");

    // 8.1.Depth Sol [Enable]
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS); // I want he one with lower depth to be drawn

    // While Loop
    //  glfwWindowShouldClose(..) true when we press on the x of the window 🤨
    while (!glfwWindowShouldClose(window))
    {
        float time = (float)glfwGetTime();

        // To make him see User Inputs and message queue 🤐
        glfwPollEvents();

        // // Execute this command
        // glClear(GL_COLOR_BUFFER_BIT);
        // 8.3. Clear Depth Color by value specified above or default = 1
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Now we need to Draw
        glUseProgram(program);
        glBindVertexArray(vertex_array);

        // 5.Define MVP 😋
        // 5.a.Perspective (Projection)
        // Syntax: 90(degree of my sight)[pi/2],aspect ratio(Width/Height) of window,znear(nearest distance i can see nearer than that won't be seen 👁👁),zfar(farthest distance i can see farther than that won't be seen 👁👁)
        glm::mat4 P = glm::perspective(glm::pi<float>() * 0.5f, 600.0f / 400.0f, 0.01f, 1000.0f);

        // 5.b View(Location of the Camera)
        // Location of the Camera 🌏,looks at what ,up
        glm::mat4 V = glm::lookAt(
            glm::vec3(2.0f * cosf(time), 1.0f, 2.0f * sinf(time)),
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f));

        // // 5.c Model
        // glm::mat4 M = glm::mat4(1.0f);
        // glm::mat4 MVP = P * V * M;

        // //6. Send MVP Uniform Value to the Vertex Shader
        // // glUniformMatrix4fv to send uniform matrix
        // // Syntax: uniform location,only 1 matrix, transpose=false,pointer to the matrix first element
        // glUniformMatrix4fv(MVP_loc, 1, false, &MVP[0][0]);

        // /* Use Triangles , start from vertex 0 , draw 6 vertices*/
        // // triangle,cout,type which is that of element ,offset
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void *)0);

        // 7.Another Model Matrix with 5 Squares[With Translation ]
        for (int i = -2; i <= 2; i++)
        {
            glm::mat4 M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, (float)i));

            glm::mat4 MVP = P * V * M;

            // Send MVP Uniform Value to the Vertex Shader
            // glUniformMatrix4fv to send uniform matrix
            // Syntax: uniform location,only 1 matrix, transpose=false,pointer to the matrix first element
            glUniformMatrix4fv(MVP_loc, 1, false, &MVP[0][0]);

            /* Use Triangles , start from vertex 0 , draw 6 vertices*/
            // triangle,cout,type which is that of element ,offset
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void *)0);
        }

        // But this Command is executed in the back Buffer screen not front
        // Call Swap to see th update 🥱
        glfwSwapBuffers(window);
    }

    // Delete Program
    glDeleteProgram(program);

    glfwDestroyWindow(window);
    glfwTerminate();
}