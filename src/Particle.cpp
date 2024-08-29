#include "Particle.h"

Particle::Particle() : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(1.0f) {}

void Particle::Update(float deltaTime) {
    Position += Velocity * deltaTime;
    Life -= deltaTime;
}
