
#include <iostream>
#include <list>

#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler

#include <GLFW/glfw3.h> // cross-platform interface for creating a graphical context,
                        // initializing OpenGL and binding inputs

#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <fstream>
#include <sstream>
#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

using namespace std;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
 
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* limit frame rate */
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        cout << "Error!" << endl;
        return 0;
    }
    
    { // used to prevent out of context error at Buffer distruction.
        float positions[] = {
            100.0f, 100.0f, 0.0f, 0.0f, // index 0
            200.0f, 100.0f, 1.0f, 0.0f, // index 1
            200.0f, 200.0f, 1.0f, 1.0f, // index 2
            100.0f, 200.0f, 0.0f, 1.0f  // index 3
        };
    
        // Index buffer
        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        unsigned int vao;
        GLCall(glGenVertexArrays(1, &vao));
        GLCall(glBindVertexArray(vao));

        VertexArray va;
        VertexBuffer vb(positions, 4 * 4 * sizeof(float));
        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        IndexBuffer ib = IndexBuffer(indices, 6);
        glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(100.0f, 0.0f, 0.0f));
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200.0f, 200.0f, 0));

        glm::mat4 mvp = proj * view * model;

        Shader shader("../res/Shaders/Basic.shader");
        shader.Bind();

        Texture texture("../res/textures/autumn_leaves.png");
        texture.Bind();
        shader.SetUniform1i("u_Texture", 0);
        shader.SetUniformMat4f("u_MVP", mvp);

        va.Unbind();
        vb.UnBind();
        ib.UnBind();
        shader.Unbind();

        Renderer renderer;

        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;

        float rIncrement = 0.05f;
        float gIncrement = 0.03f;
        float bIncrement = 0.01f;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            renderer.Clear();

            shader.Bind();
            shader.SetUniform4f("u_Color", r, g, b, 1.0f);

            renderer.Draw(va, ib, shader);

            if (r > 1.0f)
                rIncrement = -0.05f;
            else if (r < 0.0f)
                rIncrement = 0.05f;

            if (g > 1.0f)
                gIncrement = -0.03f;
            else if (g < 0.0f)
                gIncrement = 0.03f;

            if (b > 1.0f)
                bIncrement = -0.01f;
            else if (b < 0.0f)
                bIncrement = 0.01f;

            r += rIncrement;
            g += gIncrement;
            b += bIncrement;

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}