#include "Bush2.h"

Bush2::Bush2(const Shader& shader, Object& cubeObject) : ComplexModel(shader)
{
	shader.Bind();

	glm::vec3 translation(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation(1.0f, 1.0f, 1.0f);
	float angle = 0.0f;
	glm::vec3 scale(0.5f, 0.5f, 0.5f);
	glm::vec4 limeGreen(0.55f, 0.85f, 0.1f, 1.0f);
	glm::vec4 brown(0.545f, 0.271f, 0.075f, 1.0f);

	scale = glm::vec3(1.0f, 0.5f, 1.0f);
	translation = glm::vec3(0.0f, 1.5f, 0.0f);
	Model* leaves1 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves1);

	scale = glm::vec3(0.45f, 0.15f, 1.40f);
	translation = glm::vec3(-1.5f, 0.0f, 0.0f);
	Model* leaves2 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves2);

	scale = glm::vec3(0.18f, 0.1f, 1.40f);
	translation = glm::vec3(1.0f, 0.0f, 0.0f);
	Model* leaves3 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves3);

	scale = glm::vec3(1.1f, 0.1f, 0.5f);
	translation = glm::vec3(0.5f, 1.5f, 0.0f);
	Model* leaves4 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves4);

	scale = glm::vec3(0.2f, 0.13f, 1.4f);
	translation = glm::vec3(2.5f, 1.25f, 0.75f);
	Model* leaves5 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves5);

	scale = glm::vec3(1.0f, 0.25f, 1.0f);
	translation = glm::vec3(-2.0f, 0.0f, 0.0f);
	Model* leaves6 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves6);
}
