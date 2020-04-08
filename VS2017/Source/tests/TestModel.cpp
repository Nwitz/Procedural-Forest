#pragma once

#include "TestModel.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

namespace test {
	
	TestModel::TestModel()
		: m_CubeModel("res/models/heracles.obj"), m_shader("res/shaders/Basic.shader"),
		m_Translation(0.0f, 0.0f, 0.0f)
	{	

		// Camera parameters for view transform
		glm::vec3 cameraPosition(0.0f, 0.0f, 50.0f);
		glm::vec3 cameraLookAt(0.0f, 0.0f, -1.0f);
		glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);

		// Set projection matrix for shader, this won't change
		m_Proj = glm::perspective(70.0f,            // field of view in degrees
			800.0f / 600.0f,  // aspect ratio
			0.01f, 100.0f);   // near and far (near > 0)

		// Set initial view matrix
		m_View = lookAt(cameraPosition,  // eye
			cameraPosition + cameraLookAt,  // center
			cameraUp); // up
	}
	
	TestModel::~TestModel()
	{
	}
	
	void TestModel::OnUpdate(float deltaTime)
	{
	}

	void TestModel::OnRender()
	{
		GLCall(glClearColor(0.8f, 0.3f, 0.8f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
		GLCall(glEnable(GL_CULL_FACE));

		Renderer renderer;

		glm::mat4 model = glm::translate(glm::mat4(1.0f), m_Translation);
		glm::mat4 mvp = m_Proj * m_View * model;
		m_shader.Bind();
		m_shader.SetUniformMat4f("u_MVP", mvp);
		m_shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
		
		renderer.Draw(m_CubeModel.getVAO(), m_CubeModel.getIndexBuffer(), m_shader);
	}
	
	void TestModel::OnImGuiRender()
	{
		ImGui::SliderFloat3("Translation B", &m_Translation.x, -50.0f, 50.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}