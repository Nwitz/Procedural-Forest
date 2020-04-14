#pragma once

#include "Test.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <memory>
#include "Object.h"
#include "Model.h"
#include "Terrain1.h"

namespace test {

	class TestTerrain1 : public Test
	{
	public:
		TestTerrain1();
		~TestTerrain1();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		Object m_CubeObject;
		ComplexModel* m_complexModel, * m_Terrain1;
		glm::mat4 m_Proj, m_View;
		float m_BaseAngle;
		glm::vec3 m_BaseTranslation, m_BaseRotation, m_BaseScale, m_LightPosition, m_CameraPosition;
		Model m_Cube;
		Shader m_Shader;
	};
}