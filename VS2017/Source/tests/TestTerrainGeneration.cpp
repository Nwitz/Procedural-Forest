#pragma once

#include "Camera.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "TestTerrainGeneration.h"
#include "Terrain1.h"
#include "Bush.h"
#include "Rocks.h"
#include "Tree1.h"
#include "Grass.h"


namespace test {

	TestTerrainGeneration::TestTerrainGeneration()
		: m_CubeObject("res/models/cube.obj"), m_Shader("res/shaders/basic_light.shader"),
		m_BaseTranslation(-10.0f, 0.0f, 0.0f),
		m_BaseRotation(1.0f, 1.0f, 1.0f),
		m_BaseScale(0.5f, 0.5f, 0.5f),
		m_LightPosition(0.0f, 10.0f, 40.0f), m_CameraPosition(3.0f, 6.25f, 20.0f),
		m_Cube(m_CubeObject), m_BaseAngle(1.0f)
	{
		GLCall(glEnable(GL_CULL_FACE));
		glEnable(GL_DEPTH_TEST);

		m_Shader.Bind();

		m_Camera = new Camera(m_CameraPosition);

		m_HeightMapGenerator = new HeightMapGenerator(50, 50, 5);
		m_HeightMapGenerator->generateHeightMap();
		int** heightMap = m_HeightMapGenerator->getHeightMap();
		int** objectMap = m_HeightMapGenerator->getObjectMap();

		m_complexModel = new ComplexModel(m_Shader);
		m_TerrainObjects = new ComplexModel(m_Shader);
		ComplexModel* terrain;
		ComplexModel* landscapeModel;
		glm::vec3 translation;
		glm::vec3 scale, landscapeScale;

		float baseHalfCubeLength = 5;
		float cubeSize = 0.1f;

		float cubeHeight = 4 * cubeSize;
		float objectOffset = baseHalfCubeLength * 2 * cubeHeight;
		float spacing = 2 * cubeSize * baseHalfCubeLength;
		scale = glm::vec3(cubeSize, cubeHeight, cubeSize);
		landscapeScale = glm::vec3(cubeSize, cubeSize, cubeSize);
		srand(time(NULL));

		for (int i = 0; i < m_HeightMapGenerator->getRows(); i++) {
			for (int j = 0; j < m_HeightMapGenerator->getColumns(); j++) {
				terrain = new Terrain1(m_Shader, m_CubeObject);
				translation = glm::vec3(i * spacing, heightMap[i][j] * spacing / 2, j * spacing); // levels are half a cube difference in height
				terrain->setTranslation(translation);
				terrain->setScale(scale);
				terrain->computeModelMatrix();
				m_complexModel->addComplexModel(terrain);

				 // create tree if large, create rock if small
				if (objectMap[i][j] == 2 && rand() % 100 < 40) {
					landscapeModel = new Tree1(m_Shader, m_CubeObject);
					translation = glm::vec3(i * spacing, heightMap[i][j] * spacing / 2 + objectOffset, j * spacing);
					landscapeModel->setTranslation(translation);
					landscapeModel->setScale(landscapeScale);
					landscapeModel->computeModelMatrix();
					m_HeightMapGenerator->occupyPosition(i, j);

					m_TerrainObjects->addComplexModel(landscapeModel);
				}
				else if (objectMap[i][j] == 1 && rand() % 100 < 20) {
					landscapeModel = new Rocks(m_Shader, m_CubeObject);
					translation = glm::vec3(i * spacing, heightMap[i][j] * spacing / 2 + objectOffset, j * spacing);
					m_HeightMapGenerator->occupyPosition(i, j);
					landscapeModel->setTranslation(translation);
					landscapeModel->setScale(landscapeScale / 2.0f);
					landscapeModel->computeModelMatrix();

					m_TerrainObjects->addComplexModel(landscapeModel);
				}
				else {
					if (rand() % 100 < 10) {
						landscapeModel = new Grass(m_Shader, m_CubeObject);
						translation = glm::vec3(i * spacing, heightMap[i][j] * spacing / 2 + objectOffset, j * spacing);
						landscapeModel->setTranslation(translation);
						m_HeightMapGenerator->occupyPosition(i, j);
						landscapeModel->setScale(landscapeScale / 2.0f);
						landscapeModel->computeModelMatrix();

						m_TerrainObjects->addComplexModel(landscapeModel);
					}
				}
			}
		}

		
		// example of a cube that will line up exactly with top of given base
		landscapeModel = new Terrain1(m_Shader, m_CubeObject);
		translation = glm::vec3(-1 * spacing, heightMap[0][0] * spacing / 2 + objectOffset, -1 * spacing);
		landscapeModel->setTranslation(translation);
		landscapeModel->setScale(landscapeScale);
		landscapeModel->computeModelMatrix();
		m_complexModel->addComplexModel(landscapeModel);
	}

	TestTerrainGeneration::~TestTerrainGeneration()
	{
	}

	void TestTerrainGeneration::OnUpdate(float deltaTime)
	{
		m_Camera->Update(deltaTime);
	}

	void TestTerrainGeneration::OnRender()
	{
		GLCall(glClearColor(0.8f, 0.3f, 0.8f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		Renderer renderer;

		m_Proj = m_Camera->GetProjectionMatrix();
		m_View = m_Camera->GetViewMatrix();

		m_Shader.Bind();
		m_Shader.SetUniformMat4f("u_Projection", m_Proj);
		m_Shader.SetUniformMat4f("u_View", m_View);
		m_Shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
		m_Shader.SetUniform3fv("u_LightPos", m_LightPosition);
		m_Shader.SetUniform3fv("u_ViewPos", m_CameraPosition);

		m_complexModel->draw(m_Shader);
		m_TerrainObjects->draw(m_Shader);
	}

	void TestTerrainGeneration::OnImGuiRender()
	{
		ImGui::SliderFloat3("Base Translation", &m_BaseTranslation.x, -50.0f, 50.0f);
		ImGui::SliderFloat("Base Angle", &m_BaseAngle, 0.0f, 360.0f);
		if (ImGui::Button("Reset Angle")) {
			m_BaseAngle = 0.0f;
			m_BaseRotation = glm::vec3(0.0f, 0.0f, 0.0f);
		}
		ImGui::SliderFloat3("Base Rotation", &m_BaseRotation.x, -1.0f, 1.0f);
		ImGui::SliderFloat3("Base Scale", &m_BaseScale.x, 0.0f, 2.0f);
		ImGui::SliderFloat3("Camera", &m_CameraPosition.x, -100.0f, 100.0f);
		ImGui::SliderFloat3("Light", &m_LightPosition.x, -50.0f, 50.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}