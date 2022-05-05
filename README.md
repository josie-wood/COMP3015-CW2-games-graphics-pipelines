# Stylized animal fur shader
![screenshot](https://github.com/josie-wood/COMP3015-CW2-games-graphics-pipelines/blob/main/vs/media/photo.png)
## How does the user interact with your executable? How do you open and control the software you wrote (exe file)?

Run the executable by either:
* double clicking the file in the folder to run it

* navigating to the correct Release folder in the command line and entering 'Coursework2.exe' to run it.

* navigating to the correct Release folder in the command line and entering 'Coursework2.exe' to run it. 

Once the application has opened, user input can be entered to move around the scene and see the geometry from multiple angles:

* look around with the mouse
* Move backwards, forwards, left and right with WASD
* Move upwards with the space bar
* Move downwards with the left control button


## How does the program code work? How do the classes and functions fit together and who does what?

The program is built around a geometry shader which takes in a plane and outputs new geometry which is meant to represent clusters of hair.
The geometry shader is between the vertex and fragment shader stages, and takes input as triangles. It uses gl_position of each vertex as a base, and creates new vertices based on the position of this initial point to create a cluster of 'tufts' of fluff. These are outputted as a triangle strip, and are drawn in the display method using a call to glDrawElements(GL_TRIANGLES, NumVertices, GL_UNSIGNED_INT, 0);

## What makes your shader program special and how does it compare to similar things?

I started with a basic shader program I'd written for a previous module with passthrough frag and vert shaders and some basic camera movement. I wanted to create a fur shader that creates 'tufts' of fluff rather than an even covering, to give it a more organic feel. I planned on using noise to variate the placements of the additional geometry, but due to health issues, I was unable to complete the project.
This is a special program because it can take in any geometry and make a tuft of hair at every single vertices, working in the GPU to save resources compared to modelling all of these element individually.

## A link to the GitHub repo you created for public use

https://github.com/josie-wood/COMP3015-CW2-games-graphics-pipelines/blob/main/README.md

## A Link to the unlisted YouTube Video

[Unlisted youtube video link](https://youtu.be/0xAl1UYvr9U)



