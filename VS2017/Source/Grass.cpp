#include "Grass.h"

Grass::Grass(const Shader& shader, Object& cubeObject) : ComplexModel(shader)
{
	shader.Bind();

	glm::vec3 translation(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation(1.0f, 1.0f, 1.0f);
	float angle = 0.0f;
	glm::vec3 scale(0.5f, 0.5f, 0.5f);
	glm::vec4 limeGreen(0.196f, 0.804f, 0.196f, 1.0f);
	glm::vec4 yellow(0.8f, 0.7f, 0.0f, 1.0f);
	glm::vec4 dirtBrown(0.3f, 0.15f, 0.03f, 1.0f);
	glm::vec4 dimGray(0.412f, 0.412f, 0.412f, 1.0f);

	float offset = 1.5f; // used to center objects 

	scale = glm::vec3(0.025f, 0.3f, 0.01f);
	translation = glm::vec3(0.0f, offset, 0.0f);
	Model* herb1 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(herb1);

	translation = glm::vec3(1.0f, offset, 1.0f);
	Model* herb2 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(herb2);

	translation = glm::vec3(1.5f, offset, 1.5f);
	Model* herb3 = new Model(cubeObject, translation, angle, rotation, scale, limeGreen);
	addModel(herb3);

}
