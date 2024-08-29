#include "Camera.h"

Camera::Camera() : Position(0.0f, 0.0f, 3.0f), Front(0.0f, 0.0f, -1.0f), Up(0.0f, 1.0f, 0.0f), Yaw(-90.0f), Pitch(0.0f), Zoom(45.0f) {}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessKeyboard() {
    // Handle keyboard input
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset) {
    // Handle mouse movement
}
