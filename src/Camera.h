#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    DOWN, 
    UP, 
};

// Default camera values
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;

class Camera {
public:
    glm::vec3 Position, Front, Up, Right, worldUp;
    float Yaw, Pitch, Zoom;
    float MovementSpeed, MouseSensitivity;
        Camera(glm::vec3 position = glm::vec3(0.0f, 5.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH); 
    glm::mat4 GetViewMatrix();
    void ProcessKeyboard();
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
private:
    void updateCameraVectors();
};
