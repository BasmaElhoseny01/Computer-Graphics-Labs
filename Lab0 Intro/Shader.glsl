//OpenGL Shading Language (glsl)
//A shading language is a graphics programming language adapted to programming shader effects.
//     rgb
//Cyan 011
//Magneta 101
//Yellow 110
//This function GPU runs for every pixel
//Input:Fragment Coordinate
//Output:Fragment Color
//to run  Ctrl + Shift + P , shader
void mainImage(out vec4 fragColor, in vec2 fragCoord) {
    // //1.Output screen Red
    // vec4 color=vec4(1,0,0,1);//vec4 =>variable of vector of size 4
    // fragColor=color;

    // //We Can Write random access 👩‍🌾
    // // color.x=1;=> first coordinate =1
    // // color.xy=0; =>1st cor=0 and 2nd cor=0

    // /*****************************************************************************/
    // //2.fragCoord
    // fragColor=vec4(fragCoord.x,fragCoord.y,0,1);
    // //Note see the red line @ the bottom and green color @ the left

    // /****************************************************************************/
    // //3.iResolution.xy
    // //Resolution of the screen
    // //To normalize the coordinates so that not all the screen be yellow
    // vec2 uv=fragCoord/iResolution.xy;
    // //Equivalent to 😊
    // // uv.x=fragCoord.x/iResolution.x
    // // uv.y=fragCoord.y/iResolution.y
    // fragColor=vec4(uv.x,uv.y,0,1);

    // /***************************************************************************/
    // //4.Sun :D
    // vec2 uv=fragCoord/iResolution.xy;
    // float value=length(uv);//root(x^2+y^2) => scalar value
    // fragColor=vec4(value,value,value,1);

    // /***************************************************************************/
    // //4.Centered Sphere by translating the center of the sphere
    // vec2 uv=fragCoord/iResolution.xy;
    // uv.x-=0.5;
    // uv.y-=0.5;
    // float value=length(uv);//root(x^2+y^2) => scalar value
    // fragColor=vec4(value,value,value,1);

    /***************************************************************************/
    // //5.Making circle not oval shape
    // vec2 uv=fragCoord/iResolution.xy;
    // uv.x-=0.5;
    // uv.y-=0.5;
    // //Multiply by aspect ratio
    // uv.x*=iResolution.x/iResolution.y;
    // float value=length(uv);//root(x^2+y^2) => scalar value  circle equation
    // if(value<0.35){
    // //inside circle region
    // // Raduis :D
    // fragColor=vec4(1,0,0,1);
    // }
    // else{
    // fragColor=vec4(0,0,0,1);
    // }

    /***************************************************************************/
    // 5.Spiral Moving Circle
    vec2 uv = fragCoord / iResolution.xy;
    uv.x -= 0.5;
    uv.y -= 0.5;
    // Multiply by aspect ratio
    uv.x *= iResolution.x / iResolution.y;
    float value = length(uv);//root(x^2+y^2) => scalar value  circle equation
    if(value < 0.35) {
    // Raduis :D
    // value[0,0.35)
    // *100.0=[0,35)  so result of sin(value*100.0)[-1:1]  considering -1:0 => black 0:1
    //If we removed iTime it is static ⏳
        fragColor = vec4(sin(value * 100.0 + iTime * 5.0), 0, 0, 1);
    } else {
        fragColor = vec4(0, 0, 0, 1);
    }
}
