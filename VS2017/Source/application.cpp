
#include <iostream>
#include <list>

#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler

#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <fstream>
#include <sstream>
#include "EventManager.h"
#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw_gl3.h"

#include "tests/TestClearColor.h"
#include "tests/TestTexture2D.h"
#include "tests/TestModel.h"
#include "tests/TestLight.h"
#include "tests/TestComplexModel.h"

#include "tests/TestTerrain1.h"
#include "tests/TestBush1.h"
#include "tests/TestBush2.h"
#include "tests/TestBush3.h"
#include "tests/TestTree1.h"
#include "tests/TestTree2.h"
#include "tests/TestBush.h"
#include "tests/TestGrass.h"
#include "tests/TestRocks.h"
#include "tests/TestTerrainGeneration.h"

int main(void)
{
	/* Initialize window and mouse position */
	EventManager::Initialize();

    if (glewInit() != GLEW_OK) {
        std::cout << "Error!" << std::endl;
        return 0;
    }
    
    { // used to prevent out of context error at Buffer distruction.
   

        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        unsigned int vao;
        GLCall(glGenVertexArrays(1, &vao));
        GLCall(glBindVertexArray(vao));

        Renderer renderer;

        ImGui::CreateContext();
        ImGui_ImplGlfwGL3_Init(EventManager::GetWindow(), true);
        ImGui::StyleColorsDark();

        test::Test* currentTest = nullptr;
        test::TestMenu* testMenu = new test::TestMenu(currentTest);
        currentTest = testMenu;
        // testMenu->RegisterTest<test::TestClearColor>("Clear Color");
        // testMenu->RegisterTest<test::TestTexture2D>("Texture 2D");
        // testMenu->RegisterTest<test::TestModel>("Model");
        // testMenu->RegisterTest<test::TestLight>("Light");
        // testMenu->RegisterTest<test::TestComplexModel>("ComplexModel");
        testMenu->RegisterTest<test::TestTerrainGeneration>("Test Terrain Generation");
        testMenu->RegisterTest<test::TestTerrain1>("Test Terrain1");
        testMenu->RegisterTest<test::TestBush>("Test Bush");
		testMenu->RegisterTest<test::TestBush1>("Test Bush1");
		testMenu->RegisterTest<test::TestBush2>("Test Bush2");
		testMenu->RegisterTest<test::TestBush3>("Test Bush3");
        testMenu->RegisterTest<test::TestTree1>("Test Tree1");
        testMenu->RegisterTest<test::TestTree2>("Test Tree2");
        testMenu->RegisterTest<test::TestGrass>("Test Grass");
        testMenu->RegisterTest<test::TestRocks>("Test Rocks");
        
        /* Loop until the user closes the window */
        while (EventManager::CloseWindow() == false)
        {
            GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
            renderer.Clear();

            ImGui_ImplGlfwGL3_NewFrame();
            if (currentTest)
            {
				EventManager::Update();
                currentTest->OnUpdate(EventManager::GetFrameTime());
                currentTest->OnRender();
                ImGui::Begin("Test");
                if (currentTest != testMenu && ImGui::Button("<-"))
                {
                    delete currentTest;
                    currentTest = testMenu;
                }
                currentTest->OnImGuiRender();
                ImGui::End();
            }

            ImGui::Render();
            ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(EventManager::GetWindow());

            glfwPollEvents();
		}
        delete currentTest;
        if (currentTest != testMenu)
            delete testMenu;
    }
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
	EventManager::Shutdown();
    return 0;
}