#include "Bush1.h"

Bush1::Bush1(const Shader& shader, Object& cubeObject) : ComplexModel(shader)
{
	shader.Bind();

	glm::vec3 translation(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation(1.0f, 1.0f, 1.0f);
	float angle = 0.0f;
	glm::vec3 scale(0.5f, 0.5f, 0.5f);
	glm::vec4 limeGreen(0.55f, 0.85f, 0.1f, 1.0f);

	scale = glm::vec3(0.8f, 0.25f, 0.8f);
	translation = glm::vec3(-0.5f, 0.0f, 0.0f);
	Model* leaves1 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves1);

	scale = glm::vec3(0.95f, 0.3f, 0.95f);
	translation = glm::vec3(2.0f, 1.0f, 0.5f);
	Model* leaves2 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves2);

	scale = glm::vec3(0.95f, 0.3f, 0.95f);
	translation = glm::vec3(-2.5f, 1.5f, 0.5f);
	Model* leaves3 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves3);

	scale = glm::vec3(0.55f, 0.3f, 1.25f);
	translation = glm::vec3(-2.5f, 3.5f, 0.5f);
	Model* leaves4 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves4);

	scale = glm::vec3(0.55f, 0.3f, 0.5f);
	translation = glm::vec3(1.5f, 4.0f, 0.5f);
	Model* leaves5 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves5);
}
