#pragma once

#include "Test.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <memory>
#include "Object.h"
#include "Model.h"
#include "ComplexModel.h"
#include "HeightMapGenerator.h"


namespace test {

	class TestTerrainGeneration : public Test
	{
	public:
		TestTerrainGeneration();
		~TestTerrainGeneration();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		Object m_CubeObject;
		ComplexModel* m_complexModel;
		ComplexModel* m_TerrainObjects;
		HeightMapGenerator* m_HeightMapGenerator;
		float m_BaseAngle;
		glm::mat4 m_Proj, m_View;
		glm::vec3 m_BaseTranslation, m_BaseRotation, m_BaseScale, m_LightPosition, m_CameraPosition;
		Model m_Cube;
		Shader m_Shader;
	};
}