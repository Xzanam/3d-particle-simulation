#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "Camera.h"
#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<cstring>
#include<vector>


const int W_WIDTH =  1280; 
const int W_HEIGHT  = 700;


// camera
Camera camera(glm::vec3(0.0f, 0.1f, 3.0f));


//the ground plane 

glm::vec3 planeNormal = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 planePosition = glm::vec3(0.0f, -0.5f, 0.0f);  

float lastX = W_WIDTH / 2.0f;
float lastY = W_HEIGHT / 2.0f;
bool firstMouse = true;

float deltaTime = 0.0f; // Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame   


#endif