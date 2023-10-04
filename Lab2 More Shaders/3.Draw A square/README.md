# Draw A square
### Till here we have teh point that shaders doesn't have any data so we can control the no of vertices from main.cpp
🧨🎃 To draw a square we need 6 vertices


## <img align= center width=50px height=50px src="https://thumbs.gfycat.com/UnhappyJubilantLaughingthrush-size_restricted.gif"> Code Map
1. Draw A square Simply
 - Add more 3 vertices to positions array <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L126-L134">here</a>
 - Don't forget to update <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L209">glDrawArrays()</a>
 - Don't forget to update Buffer size<a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L153">glBufferData()</a>

#### But this is loss of memory there is 2 vertices repeated so we will use element buffer with  vertex buffer
2. Using Element Buffer
    - Return positions to 4 so that we only have 4 vertices <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L136-L141">here</a>
    - Define <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L144">elements</a> ie how to index inside positions to make shape out of it
    - Don't forget to update size of vertex buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L154">here</a>
    - Define element buffer <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L156-L162">here</a>
    - Don't forget [Why???????] <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L193">here</a>
      ```
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
      ```
    - Use <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L212">glDrawElements()</a> instead of <a href="https://github.com/BasmaElhoseny01/Computer-Graphics-Labs/blob/866503b2037e207ac9da1f6faba5c9b57a0cfff9/Lab2/3.Draw A square/main.cpp#L211">glDrawArrays()</a>