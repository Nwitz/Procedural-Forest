#pragma once

#include "Test.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <memory>
#include "Object.h"
#include "Model.h"

namespace test {
	
	class TestModel : public Test
	{
	public:
		TestModel();
		~TestModel();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private: 
		Object m_CubeObject;
		glm::mat4 m_Proj, m_View;
		glm::vec3 m_Translation;
		Model m_Cube;
		Shader m_shader;
	};
}