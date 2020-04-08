#pragma once

#include "Test.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <memory>
#include "Model.h"
#include "ModelInstance.h"

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
		Model m_CubeModel;
		glm::mat4 m_Proj, m_View;
		glm::vec3 m_Translation;
		ModelInstance m_Cube;
		Shader m_shader;
	};
}