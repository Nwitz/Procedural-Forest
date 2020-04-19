#include "Bush3.h"

Bush3::Bush3(const Shader& shader, Object& cubeObject) : ComplexModel(shader)
{
	shader.Bind();

	glm::vec3 translation(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation(1.0f, 1.0f, 1.0f);
	float angle = 0.0f;
	glm::vec3 scale(0.5f, 0.5f, 0.5f);
	glm::vec4 limeGreen(0.55f, 0.85f, 0.1f, 1.0f);

	float offset = 2.5f; // used to center objects 

	scale = glm::vec3(2.0f, 0.5f, 1.0f);
	translation = glm::vec3(0.0f, offset, 0.0f);
	Model* leaves1 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves1);

	scale = glm::vec3(1.0f, 0.5f, 2.0f);
	translation = glm::vec3(0.0f, offset, 0.0f);
	Model* leaves2 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves2);

	scale = glm::vec3(1.0f, 0.5f, 1.0f);
	translation = glm::vec3(0.0f, offset + 3.0f, 0.0f);
	Model* leaves3 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves3);

	scale = glm::vec3(1.0f, 0.5f, 1.5f);
	translation = glm::vec3(0.0f, offset + 1.5f, 0.0f);
	Model* leaves4 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves4);

	scale = glm::vec3(1.5f, 0.5f, 1.0f);
	translation = glm::vec3(0.0f, offset + 1.5f, 0.0f);
	Model* leaves5 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(leaves5);
}
