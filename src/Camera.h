#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    glm::vec3 Position, Front, Up;
    float Yaw, Pitch, Zoom;

    Camera();
    glm::mat4 GetViewMatrix();
    void ProcessKeyboard();
    void ProcessMouseMovement(float xoffset, float yoffset);
};
