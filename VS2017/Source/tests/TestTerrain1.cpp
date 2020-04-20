#pragma once

#include "IndexBuffer.h"
#include "VertexArray.h"
#include "TestTerrain1.h"

namespace test {

	TestTerrain1::TestTerrain1()
		: m_CubeObject("res/models/cube.obj"), m_Shader("res/shaders/basic_light.shader"),
		m_BaseTranslation(-10.0f, 0.0f, 0.0f),
		m_BaseRotation(1.0f, 1.0f, 1.0f),
		m_BaseScale(0.5f, 0.5f, 0.5f),
		m_LightPosition(0.0f, 10.0f, 40.0f), m_CameraPosition(0.0f, 10.0f, 60.0f),
		m_Cube(m_CubeObject), m_BaseAngle(1.0f)
	{

		// Camera parameters for view transform
		glm::vec3 cameraLookAt(0.0f, -0.1f, -1.0f);
		glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);

		// Set projection matrix for shader, this won't change
		m_Proj = glm::perspective(70.0f,            // field of view in degrees
			16.0f / 9.0f,  // aspect ratio
			0.01f, 100.0f);   // near and far (near > 0)

		// Set initial view matrix
		m_View = lookAt(m_CameraPosition,  // eye
			m_CameraPosition + cameraLookAt,  // center
			cameraUp); // up

		GLCall(glEnable(GL_CULL_FACE));
		glEnable(GL_DEPTH_TEST);

		m_Shader.Bind();

		m_complexModel = new ComplexModel(m_Shader);
		m_complexModel->setRotation(45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		m_complexModel->setScale(glm::vec3(0.5f, 0.5f, 0.5f));
		m_complexModel->computeModelMatrix();
		/*
		Model* bottomCube = new Model(m_CubeObject);
		Model* topTranslatedCube = new Model(m_CubeObject);
		topTranslatedCube->setTranslation(glm::vec3(10.0f, 10.0f, 1.0f));
		topTranslatedCube->setRotation(45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		topTranslatedCube->setScale(glm::vec3(1.25f, 1.25f, 1.25f));
		topTranslatedCube->computeModelMatrix();

		m_complexModel->addModel(bottomCube);
		m_complexModel->addModel(topTranslatedCube);

		*/
		m_Terrain1 = new Terrain1(m_Shader, m_CubeObject);
	}

	TestTerrain1::~TestTerrain1()
	{
	}

	void TestTerrain1::OnUpdate(float deltaTime)
	{
	}

	void TestTerrain1::OnRender()
	{
		GLCall(glClearColor(0.502f, 0.502f, 0.502f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
		Renderer renderer;

		glm::vec3 cameraLookAt(0.0f, -0.1f, -1.0f);
		glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);
		// Set initial view matrix
		m_View = lookAt(m_CameraPosition,  // eye
			m_CameraPosition + cameraLookAt,  // center
			cameraUp); // up


		m_Shader.Bind();
		m_Shader.SetUniformMat4f("u_Projection", m_Proj);
		m_Shader.SetUniformMat4f("u_View", m_View);
		m_Shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
		m_Shader.SetUniform3fv("u_LightPos", m_LightPosition);
		m_Shader.SetUniform3fv("u_ViewPos", m_CameraPosition);

		// m_complexModel->setTransforms(m_BaseTranslation, m_BaseAngle, m_BaseRotation, m_BaseScale);

		// m_complexModel->draw();

		m_Terrain1->draw();
	}

	void TestTerrain1::OnImGuiRender()
	{
		ImGui::SliderFloat3("Base Translation", &m_BaseTranslation.x, -50.0f, 50.0f);
		ImGui::SliderFloat("Base Angle", &m_BaseAngle, 0.0f, 360.0f);
		if (ImGui::Button("Reset Angle")) {
			m_BaseAngle = 0.0f;
			m_BaseRotation = glm::vec3(0.0f, 0.0f, 0.0f);
		}
		ImGui::SliderFloat3("Base Rotation", &m_BaseRotation.x, -1.0f, 1.0f);
		ImGui::SliderFloat3("Base Scale", &m_BaseScale.x, 0.0f, 2.0f);
		ImGui::SliderFloat3("Camera", &m_CameraPosition.x, -50.0f, 50.0f);
		ImGui::SliderFloat3("Light", &m_LightPosition.x, -50.0f, 50.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}