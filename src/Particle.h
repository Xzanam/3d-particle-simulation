#pragma once
#include <glm/glm.hpp>

class Particle {
public:
    glm::vec3 Position, Velocity, Color;
    float Life;

    Particle();
    void Update(float deltaTime);
};
