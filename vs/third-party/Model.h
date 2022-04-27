#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

extern GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "stb_image.h"
#include "ObjectLoader.h"

class Model
{
    public:

    Model();

    void loadFromFile(const char* filePath, const char* mtlPath);

    void draw();

    void loadTextureFromFile(const char* filePath);

    private:
    std::vector<Vertex> mesh;
    std::vector<Material> materials;

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;

    std::vector<glm::vec3> ambients;
    std::vector<glm::vec3> diffuses;
    std::vector<glm::vec3> speculars;

    std::vector<const char*> texturePaths;

    GLuint vertexbuffer;
    GLuint uvbuffer;
    GLuint normalbuffer;

    GLuint ambientbuffer;
    GLuint diffusebuffer;
    GLuint specularbuffer;

    GLuint texturebuffer;

    GLuint getProgramID() {
        GLuint i = 0;
        glGetIntegerv(GL_CURRENT_PROGRAM, (GLint*)(&i));
        return i;
    }
};