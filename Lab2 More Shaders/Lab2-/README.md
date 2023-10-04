# MPV 
#### Draw A Square with Depth

## <img align= center width=50px height=50px src="https://thumbs.gfycat.com/UnhappyJubilantLaughingthrush-size_restricted.gif"> Code Map
1. Adding glm library
  i. Add glm to <a href="">include_directories</a>in CMakeLists.txt
  ii. Add include in <a href="">main.cpp</a>
2.Note 🖋 we can use <a href="">glm:vec3</a> instead of making position <a href="">struct of 4 floats</a>
3. Use Library of Matrices in glm so we <a href="">include it</a>
4. Define MVP as uniform (send from c++) tp the vertex shader<a href="">here</a>
    - MVP is matrix of 4 (mat4)
    - MVP: Model View Perspective 
    - Multiply MVP to the vertex to vec4 to get gl_Position <a href="">here</a>
    - Note 🖋🖋 mat4(matrix4)*vec4(vector 4) = vec4(vector4) 

5. Create MPV in main.cpp
  a. Create <a href="">Projection</a> Matrix
  b. Create <a href="">View</a> Matrix
  c. Create <a href="">Model</a> Matrix

6. Set MPV uniform the MVP Matrix created in step 5
  - <a href="">glGetUniformLocation()</a>
  - <a href="">glUniformMatrix4fv()</a> ➜ to send uniform matrix

7. Modify Matrix so to have 5 squares behind each other <a href="">code</a>

8. But we have Problem with depth who is in front of who 🔗🔗
  1. Enable Depth Buffer Test <a href="">here</a>
  2. Depth Buffer Clear Value <a href="">here</a>
  3. Clear Depth Buffer <a href="">here</a>
  - Note 🗒 Depth =0 nearest thing to the screen 1:farthest point


## <img align= center width=50px height=50px src=""> Vendors
- glm ➜ A C++ Math library for graphics [we Used it so that we want the library of matrices in glm 😉]