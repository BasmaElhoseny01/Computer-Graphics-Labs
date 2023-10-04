# Attribute
### Send Data from c++ code to shaders

- The problem is that the data is hard coded inside the shaders we need to send it from main => so use uniform 
- But Uniform has limited size also i want this data to be variable in size so instead of drawing only 3 vertices now we can draw square and so on 
- The data in main.cpp is stored in RAM Not seen by GPU 👀👀 so wwe put it inside a buffer seen by the GPU and we control how often it is updated by the type of this buffer

## <img align= center width=50px height=50px src="https://thumbs.gfycat.com/UnhappyJubilantLaughingthrush-size_restricted.gif"> Code Map

1. Putting Positions vector inside buffer
    - Create Data (positions) to be used by the GPU <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L126-L131">positions</a>
    - Create Buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L150-L153">here</a>
    - Put Data inside the buffer created <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L159">glBufferData()</a>
    - use Vertex Array to Read Data from Buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L172-L174">as previous lab</a>
    - Make attribute in the vertex shader to take positions from buffer<a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/assets/shaders/simple.vert#L10">here</a>
    - Get position attribute location <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L179">glGetAttribLocation()</a> & enable it <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L181">glEnableVertexAttribArray()</a>
    - 🧨🧨 How to Read Data from Buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L185">glVertexAttribPointer()</a>
2. Same idea 🌩 for the colors array in the </a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/assets/shaders/simple.vert">Vertex Shader</a> 
    - Sol(1):Make another separate buffer for this attribute
        - Pros: Separated Data so we can modify one independent of the other
        - Cons: Handling many objects for example we need to delete all these buffers @ end
    - Sol(2):Use Same Buffer Created Above and put data for position at the beginning and data for color at the end
        - Pros:Less Objects and Data is near to each other in the memory
        - Cons: if we have a lot of locations then the position of each vertex is @ beginning while location far from it
    - Sol(3):Store Color of each element immediately after it <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L133-L138">here</a>
        - <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L133-L138">positions[3 * 7]</a>
        - Define <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/assets/shaders/simple.vert#L13">in color</a> in the vertex shader
        - Update Size of the Buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L162">here</a>
        - Read Data from Buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L188">here</a>
3. Enhancement in Memory
    - Color only need 1 byte and we stored for it 4 bytes float <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L135">here</a> 🎈sol: Define a Data Structure instead
    - Define <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L14-L29">Vertex Struct</a>
    - Change <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L140-L145">position array</a> type
    - Update Size of the Buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L165">here</a>
    - Read position Data from Buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L191">here</a>
    - Read color  Data from Buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L205">here</a>
    - Notice usage of normalized <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L205">here</a>
4. Modifying in point that we get Attribute position to be able to be used by many shaders @ the same time using teh same vertex array without need to modify it 
- Modify in Vertex shader use <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/assets/shaders/simple.vert#L16-L17">layout</a>
- no need to use glGetAttribLocation() instead use <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Attribute/main.cpp#L180">layout number</a>
