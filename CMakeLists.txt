cmake_minimum_required(VERSION 3.10)
project(ParticleSimulation)

set(CMAKE_CXX_STANDARD 17)

# # Find and link GLFW
# find_package(GLFW3 REQUIRED)
# # Find and link glm
# find_package(glm REQUIRED)

# Include directories
include_directories(include)

# Add glad.c to the project
add_executable(ParticleSimulation src/main.cpp src/Shader.cpp src/Particle.cpp src/Camera.cpp src/glad.c)

# Link the necessary libraries
target_link_libraries(ParticleSimulation ${GLFW_LIBRARIES} -lGL -lglfw -lglm)
