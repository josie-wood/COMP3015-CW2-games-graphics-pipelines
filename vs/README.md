# 2021-COMP3016-W2: Free Project
# Toony Grass Shader

## How to run the project?

Run the ToonyGrassShader.exe executable. 
Press esc to close the window when you're done. 

## How does the user interact with your executable? How does program code work?

My shader takes in a subdivided plane and uses a geometry shader to generate blades of grass at each vertex of this plane.

The geometry reads in the point array, and from each vertex it creates more vertices which form a triangle strip. 

Users can move around the scene with the arrow keys/ WASD keys and cursor movement. 

The number of grass blades generated at each vertex can be manipulated by the user - press the minus key to decrease number of blades down to a minimum of one, and press the equals key to increase the number of blades up to a maximum of five. 

This is handled by a for loop in the geometry shader. User input is collect in getUserInput() in the project.cpp file, which increases or descreases the numBlades value, which is accessible as a uniform value in the shader. 

The shader loop is then interated through this many times to produce the given number of blades at that point. The angle of glass blades is calculated using the number of glass blades so each blade in a cluster has a different top point and they fan out. 

Users can also toggle between 4 different colour modes with number keys 1 - 4. This changes the two colours passed to the fragment shader for the base and tip of each blade of grass.

Additionally, users can toggle flowers on and off with the f key. Each colour mode has a differently coloured flower. 

### Controls
* arrow keys or WASD keys - move camera forwards, backwards, left, right
* Space key - move camera up
* Left Ctrl - move camera down
* Cursor - look around with camera
* minus key - decrease num of blades
* equals key - increase num of blades
* 1 - summer colours
* 2 - spring colours
* 3 - autumn colours
* 4 - winter colours
* f key - toggle flowers
* esc - close application

## What makes your program special and how does it compare to similar things? 

The majority of grass shaders either generate a single blade of grass at each vertex to allow them to be affected by physics, or they use billboard images of grass with a fixed number of blades in each cluster. 

My project allows customisation of number of blades of grass at runtime, and is extendable to allow the introduction of randomness and other variables.

I started with a basic geometry pass through shader, and expanded that myself to create new geometry for the grass blades. 
I used online resources to figure out how to do camera movement and create all of seperate matrices required for this. 
Everything else is of my own design and creation. 

## VIDEO WALKTHROUGH
Project demo is available on youtube here: https://youtu.be/hjwVtQOA-t0
