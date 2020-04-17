#include "Bush3.h"

Bush3::Bush3(const Shader& shader, Object& cubeObject) : ComplexModel(shader)
{
	shader.Bind();

	glm::vec3 translation(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation(1.0f, 1.0f, 1.0f);
	float angle = 0.0f;
	glm::vec3 scale(0.5f, 0.5f, 0.5f);
	glm::vec4 limeGreen(0.55f, 0.85f, 0.1f, 1.0f);
	glm::vec4 brown(0.545f, 0.271f, 0.075f, 1.0f);

	scale = glm::vec3(1.0f, 0.5f, 1.0f);
	translation = glm::vec3(5.0f, 0.0f, 0.0f);
	Model* leaves1 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves1);

	scale = glm::vec3(1.0f, 0.5f, 1.0f);
	translation = glm::vec3(0.0f, 0.0f, 5.0f);
	Model* leaves2 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves2);

	scale = glm::vec3(1.0f, 1.5f, 1.0f);
	translation = glm::vec3(0.0f, 5.0f, 0.0f);
	Model* leaves3 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves3);
}
