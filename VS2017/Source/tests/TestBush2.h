#pragma once

#include "Test.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <memory>
#include "Object.h"
#include "Model.h"
#include "Bush2.h"

namespace test {

	class TestBush2 : public Test
	{
	public:
		TestBush2();
		~TestBush2();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		Object m_CubeObject;
		ComplexModel* m_complexModel, * m_Bush2;
		glm::mat4 m_Proj, m_View;
		float m_BaseAngle;
		glm::vec3 m_BaseTranslation, m_BaseRotation, m_BaseScale, m_LightPosition, m_CameraPosition;
		Model m_Cube;
		Shader m_Shader;
	};
}