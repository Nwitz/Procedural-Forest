#include "BasicModelExtension.h"

BasicModelExtension::BasicModelExtension(const Shader& shader, Object &cubeObject) : ComplexModel(shader)
{
	shader.Bind();


	// 4 cube base with single cube on top
	glm::vec3 translation(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation(1.0f, 1.0f, 1.0f);
	float angle = 0.0f;
	glm::vec3 scale(0.5f, 0.5f, 0.5f);
	glm::vec4 green(0.3f, 0.8f, 0.1f, 1.0f);
	glm::vec4 yellow(0.8f, 0.7f, 0.0f, 1.0f);

	translation = glm::vec3(-2.5f, 0.0f, -2.5f);
	Model *farLeft = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(farLeft);

	translation = glm::vec3(2.5f, 0.0f, -2.5f);
	Model* farRight = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(farRight);

	translation = glm::vec3(-2.5f, 0.0f, 2.5f);
	Model* closeLeft = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(closeLeft);

	translation = glm::vec3(2.5f, 0.0f, 2.5f);
	Model* closeRight = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(closeRight);

	translation = glm::vec3(0.0f, 2.5f, 0.0f);
	Model* top = new Model(cubeObject, translation, angle, rotation, scale, yellow);
	addModel(top);
}
