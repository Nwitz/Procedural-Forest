#pragma once

#include "TestLight.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include <iostream>

namespace test {
	
	TestLight::TestLight()
		: m_CubeObject("res/models/cube.obj"), m_Shader("res/shaders/basic_light.shader"),
		m_TranslationA(-10.0f, 0.0f, 0.0f), m_TranslationB(10.0f, 0.0f, 0.0f),
		m_LightPosition(0.0f, 10.0f, 40.0f), m_CameraPosition(0.0f, 10.0f, 40.0f),
		m_Cube(m_CubeObject)
	{	

		// Camera parameters for view transform
		glm::vec3 cameraLookAt(0.0f, -0.1f, -1.0f);
		glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);

		// Set projection matrix for shader, this won't change
		m_Proj = glm::perspective(90.0f,            // field of view in degrees
			1.0f,  // aspect ratio
			0.01f, 100.0f);   // near and far (near > 0)

		// Set initial view matrix
		m_View = lookAt(m_CameraPosition,  // eye
			m_CameraPosition + cameraLookAt,  // center
			cameraUp); // up

		GLCall(glEnable(GL_CULL_FACE));
		glEnable(GL_DEPTH_TEST);

		unsigned int uint = 5;
		std::cout << uint / 2 << std::endl;
	}
	
	TestLight::~TestLight()
	{
	}
	
	void TestLight::OnUpdate(float deltaTime)
	{
	}

	void TestLight::OnRender()
	{
		GLCall(glClearColor(0.8f, 0.3f, 0.8f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		glm::vec3 cameraLookAt(0.0f, -0.1f, -1.0f);
		glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);
		// Set initial view matrix
		m_View = lookAt(m_CameraPosition,  // eye
			m_CameraPosition + cameraLookAt,  // center
			cameraUp); // up

		glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationA);
		m_Shader.Bind();
		m_Shader.SetUniformMat4f("u_Projection", m_Proj);
		m_Shader.SetUniformMat4f("u_View", m_View);
		m_Shader.SetUniformMat4f("u_Model", model);
		m_Shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
		m_Shader.SetUniform3fv("u_LightPos", m_LightPosition);
		m_Shader.SetUniform3fv("u_ViewPos", m_CameraPosition);
		m_Cube.draw(m_Shader);

		model = glm::translate(glm::mat4(1.0f), m_TranslationB);
		m_Shader.SetUniformMat4f("u_Model", model);
		m_Cube.draw(m_Shader);
		
	}
	
	void TestLight::OnImGuiRender()
	{
		ImGui::SliderFloat3("Translation A", &m_TranslationA.x, -50.0f, 50.0f);
		ImGui::SliderFloat3("Translation B", &m_TranslationB.x, -50.0f, 50.0f);
		ImGui::SliderFloat3("Camera", &m_CameraPosition.x, -50.0f, 50.0f);
		ImGui::SliderFloat3("Light", &m_LightPosition.x, -50.0f, 50.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}