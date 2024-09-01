#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>
#include "constants.h"
#include "Shader.h"
#include "Particle.h"
#include "Camera.h"
#include "Sphere.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn); 
void processCameraMovement(GLFWwindow* window); 


int main() {
    // Initializ GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Set OpenGL version and core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Particle Simulation", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD before using any OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set viewport and callbacks
    glViewport(0, 0, W_WIDTH, W_HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback); 
    
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); 
    Shader particleShader("../shaders/particle.vert", "../shaders/particle.frag");
    Shader groundShader("../shaders/ground.vert", "../shaders/ground.frag"); 
    // Particle setup here
    //traingle check //
    float vertices[] = {//

        -0.5f, -0.5f, -0.5f, // 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f, // 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f, // 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f, // 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, // 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, // 0.0f, 0.0f,
//
        -0.5f, -0.5f,  0.5f, // 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f, // 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, // 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f, // 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, // 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, // 0.0f, 0.0f,
//
        -0.5f,  0.5f,  0.5f, // 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, // 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, // 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, // 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, // 0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, // 1.0f, 0.0f,
//
         0.5f,  0.5f,  0.5f, // 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f, // 1.0f, 1.0f,
         0.5f, -0.5f, -0.5f, // 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, // 0.0f, 1.0f,
         0.5f, -0.5f,  0.5f, // 0.0f, 0.0f,
         0.5f,  0.5f,  0.5f, // 1.0f, 0.0f,
//
        -0.5f, -0.5f, -0.5f, // 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, // 1.0f, 1.0f,
         0.5f, -0.5f,  0.5f, // 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f, // 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, // 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, // 0.0f, 1.0f,
//
        -0.5f,  0.5f, -0.5f, // 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f, // 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f, // 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, // 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, // 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, // 0.0f, 1.0f
    };//

   //arraybuffers for ground 
  unsigned int VAO1, VBO1;
 
  glGenBuffers(1, &VBO1); 
  glGenVertexArrays(1, &VAO1); 

  glBindVertexArray(VAO1);

  glBindBuffer(GL_ARRAY_BUFFER, VBO1); 
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0 ); 
  glEnableVertexAttribArray(0); 



    unsigned int VBO; //
    unsigned int VAO; 

    glGenBuffers(1, &VBO); 
    glGenVertexArrays(1, &VAO); 
    glBindVertexArray(VAO); 

    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3 , GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); 
    glEnableVertexAttribArray(0); 

    Sphere ball(0.5, 72, 36); 

 
  glEnable(GL_DEPTH_TEST); 



  

    // Main loop
    while (!glfwWindowShouldClose(window)) {

        float currentFrame  = static_cast<float>(glfwGetTime()); 
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame; 
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); 
        glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT); 
       
       
         // create transformations
        glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        model = glm::translate(model, glm::vec3(0.0f, 0.5f, 0.0f));
        glm::mat4 view          = camera.GetViewMatrix();
        glm::mat4 projection    = glm::mat4(1.0f);
        // model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
        projection = glm::perspective(glm::radians(45.0f), (float)W_WIDTH / (float)W_HEIGHT, 0.1f, 100.0f);
      
       //ground rendering 
       groundShader.use(); 
   
        glm::mat4 ground_model = glm::mat4(1.0f); // Identity matrix
        ground_model = glm::scale(ground_model, glm::vec3(1000.0f, 0.1f, 1000.0f)); // Scale to make it large and thin
        ground_model = glm::translate(ground_model, planePosition); // Move it slightly down to ensure it's visible
        groundShader.setMat4("model", ground_model ); 
        groundShader.setMat4("view", view); 
        groundShader.setMat4("projection", projection); 
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0 , 36);


        particleShader.use();
        // retrieve the matrix uniform locations
        particleShader.setMat4("model", model);
        particleShader.setMat4("view", view); 
        
        // Render particles
        // glBindVertexArray(VAO); 
        // glDrawArrays(GL_TRIANGLES, 0, 36); 

       particleShader.setMat4("projection", projection);      

       ball.draw();
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    processCameraMovement(window); 
    // std::cout<<camera.Position.x;
}
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{


    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);
    if (firstMouse) // initially set to true
    {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
    }   

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed: y ranges bottom to top
    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void processCameraMovement(GLFWwindow* window)
{

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_SPACE ) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);


    // else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_RELEASE)
    //     camera.thirdCamera(TPP, deltaTime,0);

}