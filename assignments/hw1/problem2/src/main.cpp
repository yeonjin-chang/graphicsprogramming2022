#define GLM_ENABLE_EXPERIMENTAL
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))  
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))  
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "gameobjects.h"
#include "geometry_primitives.h"
#include <iostream>
#include <vector>
#include "text_renderer.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window, Bar& bar, float dt);

// setting
const unsigned int SCR_WIDTH = 900;
const unsigned int SCR_HEIGHT = 600;

bool previousKeyState[1024];

int main()
{
    
    // glfw: initialize and configure
    // ------------------------------'
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
    // ------------------------------------
    Shader ourShader("../shaders/shader.vs", "../shaders/shader.fs"); // you can name your shader files however you like


    /////////////////////////////////////////////////////
    // TODO : Define VAO and VBO for triangle and quad(bar).
    /////////////////////////////////////////////////////



    std::vector<Entity> entities;


    TextRenderer  *Text;
    Text = new TextRenderer(SCR_WIDTH, SCR_HEIGHT);
    Text->Load("../fonts/OCRAEXT.TTF", 24);

    Bar bar{ 0,0,0 };

    // render loop
    // -----------
    float generationInterval = 0.3f;
    float dt = 0.0f;
    int score = 0;

    float barWidth = 0.3f;
    float barHeight = 0.05f;
    float barYPosition = -0.8f;
    
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window, bar, dt);

        // clear background
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        /////////////////////////////////////////////////////
        // TODO : Main Game Loop
        /////////////////////////////////////////////////////

        // (1) generate new triangle at the top of the screen for each time interval
        // (2) make triangles fall and rotate!!!!!
        // (3) Every triangle has different shape, falling speed, rotating speed.
        // (4) Render a red box
        // (5) Implement simple collision detection. Details are on the pdf file.
        // (6) Visualize the score & print score (you can use TextRenderer)

        
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }


    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window, Bar& bar, float dt)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    //////////////////////////////////
    // TODO : make the bar movable (consider interval time dt!)
    //////////////////////////////////

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
