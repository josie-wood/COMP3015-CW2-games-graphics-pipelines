//////////////////////////////////////////////////////////////////////////////
//
//  games graphics pipelines cw 2 - untitled
//
//////////////////////////////////////////////////////////////////////////////

#include "GL/glew.h"
#include "GL/freeglut.h"
#include "GLFW/glfw3.h"
#include "LoadShaders.h"
#include <glm/glm.hpp> //includes GLM
#include "glm/ext/vector_float3.hpp"
#include "glm/fwd.hpp"
#include <glm/ext/matrix_transform.hpp> // GLM: translate, rotate
#include <glm/ext/matrix_clip_space.hpp> // GLM: perspective and ortho 
#include <glm/gtc/type_ptr.hpp> // GLM: access to the value_ptr

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include<vector>

#include "Project.h"


enum VAO_IDs { Triangles, Indices, Colours, Tex, NumVAOs = 2 };
enum Buffer_IDs { ArrayBuffer, NumBuffers = 4 };
enum Attrib_IDs { vPosition = 0, cPosition = 1, tPosition = 2 };

GLuint  VAOs[NumVAOs];
GLuint  Buffers[NumBuffers];
GLuint texture1;

const GLuint  NumVertices = 100;
GLFWwindow* window;
glm::mat4 model;

// position
glm::vec3 position = glm::vec3(0, -0.5, 3);
// horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// vertical angle : 0, look at the horizon
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 0.01f; // 3 units / second
float mouseSpeed = 0.0005f;
float lastInput = 0;
float deltaTime = 0;
float lastFrame = 0;

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;


float numBlades = 3;
int seasonIndicator = 1;
vec4 baseColour = vec4(0, 0.2, 0, 1.0);
vec4 tipColour = vec4(0, 0.6, 0, 1.0);
float flowers = 0;
vec4 flowerColour = vec4(1, 1, 1, 1);

GLuint program;

glm::mat4 getProjectionMatrix()
{
	return ProjectionMatrix;
}

glm::mat4 getViewMatrix()
{
	return ViewMatrix;
}

//----------------------------------------------------------------------------
//
// init
//
#define BUFFER_OFFSET(a) ((void*)(a))


void
init(void)
{
	ShaderInfo  shaders[] =
	{
		{ GL_VERTEX_SHADER, "media/cw2.vert" },
		//{ GL_VERTEX_SHADER, "media/passthrough.vert" },

		{ GL_GEOMETRY_SHADER,  "media/cw2.geometry" },
				
		{ GL_FRAGMENT_SHADER, "media/cw2.frag" },
		//{ GL_FRAGMENT_SHADER, "media/passthrough.frag" },

		{ GL_NONE, NULL }
	};

	program = LoadShaders(shaders);
	glUseProgram(program);

	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[0]);

	// setting up the cube

#pragma region cubeinfo




	//GLfloat vertices[] = {
	//-0.5f, -0.5f, -0.5f, //0 b l
	// 0.5f, -0.5f, -0.5f, //1 b r
	// 0.5f,  0.5f, -0.5f, //2 t r
	// 0.5f,  0.5f, -0.5f, //3 t r
	//-0.5f,  0.5f, -0.5f, //4 t l 
	//-0.5f, -0.5f, -0.5f, //5 b l

	//-0.5f, -0.5f,  0.5f, //6 b l
	// 0.5f, -0.5f,  0.5f, //7 b r
	// 0.5f,  0.5f,  0.5f, //8 t r
	// 0.5f,  0.5f,  0.5f, //9 t r 
	//-0.5f,  0.5f,  0.5f, //10 t l
	//-0.5f, -0.5f,  0.5f, //11 b l

	//-0.5f,  0.5f,  0.5f,
	//-0.5f,  0.5f, -0.5f,
	//-0.5f, -0.5f, -0.5f,
	//-0.5f, -0.5f, -0.5f,
	//-0.5f, -0.5f,  0.5f,
	//-0.5f,  0.5f,  0.5f,

	// 0.5f,  0.5f,  0.5f,
	// 0.5f,  0.5f, -0.5f,
	// 0.5f, -0.5f, -0.5f,
	// 0.5f, -0.5f, -0.5f,
	// 0.5f, -0.5f,  0.5f,
	// 0.5f,  0.5f,  0.5f,

	//-0.5f, -0.5f, -0.5f, // b l b
	// 0.5f, -0.5f, -0.5f, // b r b
	// 0.5f, -0.5f,  0.5f, // b r f
	// 0.5f, -0.5f,  0.5f, // b r b
	//-0.5f, -0.5f,  0.5f, // b l f
	//-0.5f, -0.5f, -0.5f, // b l b

	//-0.5f,  0.5f, -0.5f,
	// 0.5f,  0.5f, -0.5f,
	// 0.5f,  0.5f,  0.5f,
	// 0.5f,  0.5f,  0.5f,
	//-0.5f,  0.5f,  0.5f,
	//-0.5f,  0.5f, -0.5f,
	//};



	/*GLfloat normals[]{
	0.0f,  0.0f, -1.0f,
	0.0f,  0.0f, -1.0f,
	0.0f,  0.0f, -1.0f,
	0.0f,  0.0f, -1.0f,
	0.0f,  0.0f, -1.0f,
	0.0f,  0.0f, -1.0f,

	0.0f,  0.0f, 1.0f,
	0.0f,  0.0f, 1.0f,
	0.0f,  0.0f, 1.0f,
	0.0f,  0.0f, 1.0f,
	0.0f,  0.0f, 1.0f,
	0.0f,  0.0f, 1.0f,

	-1.0f,  0.0f,  0.0f,
	-1.0f,  0.0f,  0.0f,
	-1.0f,  0.0f,  0.0f,
	-1.0f,  0.0f,  0.0f,
	-1.0f,  0.0f,  0.0f,
	-1.0f,  0.0f,  0.0f,

	1.0f,  0.0f,  0.0f,
	1.0f,  0.0f,  0.0f,
	1.0f,  0.0f,  0.0f,
	1.0f,  0.0f,  0.0f,
	1.0f,  0.0f,  0.0f,
	1.0f,  0.0f,  0.0f,

	0.0f, -1.0f,  0.0f,
	0.0f, -1.0f,  0.0f,
	0.0f, -1.0f,  0.0f,
	0.0f, -1.0f,  0.0f,
	0.0f, -1.0f,  0.0f,
	0.0f, -1.0f,  0.0f,

	0.0f,  1.0f,  0.0f,
	0.0f,  1.0f,  0.0f,
	0.0f,  1.0f,  0.0f,
	0.0f,  1.0f,  0.0f,
	0.0f,  1.0f,  0.0f,
	0.0f,  1.0f,  0.0f };*/

	//GLuint indices[][3] = {  // note that we start from 0!
	//	{0, 1, 2},  // first Triangle front
	//	{3, 4, 5},   // second Triangle

	//	{8, 7, 6 },
	//	{11, 10, 9 },

	//	{14, 13, 12 },
	//	{17, 16, 15 },

	//	{18, 19, 20 },
	//	{21, 22, 23 },

	//	{26, 25, 24 },
	//	{29, 28, 27 },

	//	{30, 31, 32 },  // first Triangle back
	//	{33, 34, 35 }   // second Triangle
	//};

#pragma endregion

//plane info

GLfloat vertices[][3] = {



	//ROW 4
	{-1.0, -2, -0.5},
	{-0.5, -2, -0.5},
	{0.0,  -2, -0.5},
	{0.5,  -2, -0.5},
	{1.0,  -2, -0.5},

	//ROW 5
	{-1.0, -2, -1.0},
	{-0.5, -2, -1.0},
	{0.0,  -2, -1.0},
	{0.5,  -2, -1.0},
	{1.0,  -2, -1.0},

	//ROW 3
	{-1.0, -2, 0.0},
	{-0.5, -2, 0.0},
	{0.0,  -2, 0.0},
	{0.5,  -2, 0.0},
	{1.0,  -2, 0.0},

	//ROW 2
	{-1.0, -2, 0.5},
	{-0.5, -2, 0.5},
	{0.0,  -2, 0.5},
	{0.5,  -2, 0.5},
	{1.0,  -2, 0.5},

	//ROW 1
	{-1.0, -2, 1.0},
	{-0.5, -2, 1.0},
	{0.0,  -2, 1.0},
	{0.5,  -2, 1.0},
	{1.0,  -2, 1.0},


};
GLuint indices[][3] = {  // note that we start from 0!
	//tri row 1

	0,	1,	5,
	1,	2, 6,
	2,	3,	7,
	3,	4,	8,

	//TRI ROW 2
	5,	6,	10,
	6,	7,	11,
	7,	8,	12,
	8,	9,	13,

	//TRI ROW 3
	10,	11,	15,
	11,	12,	16,
	12,	13,	17,
	13,	14,	18,

	//tri row 4
	15,	16,	20,
	16,	17,	21,
	17,	18,	22,
	18,	19,	23,

	//bottom left corner
	23,	19,	24,


};


	glGenBuffers(NumBuffers, Buffers);
	
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[Triangles]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffers[Indices]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	

	glVertexAttribPointer(vPosition, 3, GL_FLOAT,
		GL_FALSE, 0, BUFFER_OFFSET(0));
	


	glEnableVertexAttribArray(vPosition);
	glEnableVertexAttribArray(cPosition);
	glEnableVertexAttribArray(tPosition);

	glBindVertexArray(VAOs[1]);


	glGenBuffers(NumBuffers, Buffers);

	glBindBuffer(GL_ARRAY_BUFFER, Buffers[Triangles]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffers[Indices]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);



	glVertexAttribPointer(vPosition, 3, GL_FLOAT,
		GL_FALSE, 0, BUFFER_OFFSET(0));





	// creating the model matrix
	model = glm::mat4(1.0f);
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	model = glm::rotate(model, glm::radians(-00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -1.0f));

	////add model matrix to shader
	//int modelLoc = glGetUniformLocation(program, "m");
	//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model[0]));


	// creating the view matrix
	

	glm::mat4 view = glm::lookAt(
		glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);

	////add view matrix to shader

	//int viewLoc = glGetUniformLocation(program, "v");
	//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view[0]));

	// creating the projection matrix
	glm::mat4 projection = glm::perspective(45.0f, 4.0f / 3, 0.1f, 20.0f);

	////add projection to shader
	//int projLoc = glGetUniformLocation(program, "p");
	//glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection[0]));

	// Adding all matrices up to create combined matrix
	glm::mat4 mvp = projection * view * model;


	////adding the Uniform to the shader
	//int mvpLoc = glGetUniformLocation(program, "mvp");
	//glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));



	glEnableVertexAttribArray(vPosition);
	glEnableVertexAttribArray(cPosition);
	glEnableVertexAttribArray(tPosition);

	//adding the num blades uniform to the shader
	GLint numBladesLoc = glGetUniformLocation(program, "numBlades");
	glUniform1f(numBladesLoc, numBlades);

	//add season indicator uniform to shader
	GLint seasonIndicatorLoc = glGetUniformLocation(program, "seasonIndicator");
	glUniform1f(seasonIndicatorLoc, seasonIndicator);

	//add baseCol uniform to shader
	GLint baseColourLoc = glGetUniformLocation(program, "baseColour");
	glUniform4f(baseColourLoc, baseColour.x, baseColour.y, baseColour.z, baseColour.w);

	//add baseCol uniform to shader
	GLint tipColourLoc = glGetUniformLocation(program, "tipColour");
	glUniform4f(tipColourLoc, tipColour.x, tipColour.y, tipColour.z, tipColour.w);

	//add flowers int to shader
	GLint flowersLoc = glGetUniformLocation(program, "flowers");
	glUniform1f(flowersLoc, flowers);

	//add add flower col uniform to shader
	GLint flowerColourLoc = glGetUniformLocation(program, "flowerColour");
	glUniform4f(flowerColourLoc, flowerColour.x, flowerColour.y, flowerColour.z, flowerColour.w);

}



//----------------------------------------------------------------------------
//
// display
//

void
display(void)
{
	static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };

	glClearBufferfv(GL_COLOR, 0, black);
	glClear(GL_COLOR_BUFFER_BIT);
	// bind textures on corresponding texture units
	glFrontFace(GL_CW);
	//glCullFace(GL_BACK);
	//glEnable(GL_CULL_FACE);

	glm::mat4 ModelViewMatrix = model * getViewMatrix();		
	
	// creating the projection matrix
	glm::mat4 projection = getProjectionMatrix();

	// Adding all matrices up to create combined matrix
	glm::mat4 mvp = projection * ModelViewMatrix;

	//adding the Uniforms to the shader
	int mvpLoc = glGetUniformLocation(program, "mvp");
	glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));

	int mLoc = glGetUniformLocation(program, "m");
	glUniformMatrix4fv(mLoc, 1, GL_FALSE, glm::value_ptr(model));

	int vLoc = glGetUniformLocation(program, "v");
	glUniformMatrix4fv(vLoc, 1, GL_FALSE, glm::value_ptr(getViewMatrix()));

	int pLoc = glGetUniformLocation(program, "p");
	glUniformMatrix4fv(pLoc, 1, GL_FALSE, glm::value_ptr(getProjectionMatrix()));


	//modify position using mv & p
	glBindVertexArray(VAOs[0]);
	//glBindTexture(GL_TEXTURE_2D, texture1);
	
	//glDrawArrays(GL_POINTS, 0, 50);
	//glDrawElements(GL_TRIANGLES, NumVertices, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_POINTS, 0, 4);
	//glDrawElements(GL_POINTS, 36, GL_UNSIGNED_INT, 0);
	glDrawElements(GL_TRIANGLES, NumVertices, GL_UNSIGNED_INT, 0);
}




//----------------------------------------------------------------------------
//
// controls
//



void computeMatricesFromInputs()
{
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	//get orientation
	//mouse pos
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	////reset for next frame
	glfwSetCursorPos(window, 400, 300);

	//calulate viewing angles
	horizontalAngle += mouseSpeed * deltaTime * float(400 - xpos);
	verticalAngle += mouseSpeed * deltaTime * float(300 - ypos);

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
		);

	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
		);

	// Up vector : perpendicular to both direction and right
	glm::vec3 up = glm::cross(right, direction);

	// Move forward
	if (glfwGetKey(window, GLFW_KEY_UP) || glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey(window, GLFW_KEY_DOWN) || glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_RIGHT) || glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_LEFT) || glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		position -= right * deltaTime * speed;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		position += up * deltaTime * speed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		position -= up * deltaTime * speed;
	}


	// Projection matrix : 45&deg; Field of View, 4:3 ratio, display range : 0.1 unit <-> 20 units
	ProjectionMatrix = glm::perspective(45.0f, 4.0f / 3, 0.1f, 20.0f);
	

	// Camera matrix
	ViewMatrix = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
		);

}

void getUserInput(float time)
{
	//USER INPUT HERE
}

//----------------------------------------------------------------------------
//
// main
//
int
main(int argc, char** argv)
{
	glfwInit();

	window = glfwCreateWindow(800, 600, "UNTITLED CW 2 PROJECT", NULL, NULL);

	glfwMakeContextCurrent(window);
	glewInit();

	init();
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//set up timer
	GLfloat timer = 0.0f;

	//user input view stuff
	do {

		// ...
			// uncomment to draw only wireframe 
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		
		// Compute the MVP matrix from keyboard and mouse input
		computeMatricesFromInputs();

		//get user input for shader manipulation
		getUserInput(timer);

		// ...
		display();
		glfwSwapBuffers(window);
		glfwPollEvents();

		//inc timer
		timer += deltaTime;
	}
	// Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
	
	glfwDestroyWindow(window);

	glfwTerminate();
	
}
