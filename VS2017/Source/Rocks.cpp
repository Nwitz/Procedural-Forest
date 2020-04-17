#include "Rocks.h"

Rocks::Rocks(const Shader& shader, Object& cubeObject) : ComplexModel(shader)
{
	shader.Bind();


	// 4 cube base with single cube on top
	glm::vec3 translation(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation(1.0f, 1.0f, 1.0f);
	float angle = 0.0f;
	glm::vec3 scale(0.5f, 0.5f, 0.5f);
	glm::vec4 limeGreen(0.196f, 0.804f, 0.196f, 1.0f);
	glm::vec4 yellow(0.8f, 0.7f, 0.0f, 1.0f);
	glm::vec4 dirtBrown(0.3f, 0.15f, 0.03f, 1.0f);
	glm::vec4 dimGray(0.412f, 0.412f, 0.412f, 1.0f);

	scale = glm::vec3(0.3f, 0.2f, 0.3f);
	translation = glm::vec3(0.0f, 0.0f, 0.0f);
	Model* rock1 = new Model(cubeObject, translation, angle, rotation, scale, dimGray);
	addModel(rock1);

	scale = glm::vec3(0.2f, 0.05f, 0.2f);
	translation = glm::vec3(0.0f , 1.0f, 0.0f);
	Model* rock2 = new Model(cubeObject, translation, angle, rotation, scale, dimGray);
	addModel(rock2);

	scale = glm::vec3(0.2f, 0.1f, 0.25f);
	translation = glm::vec3(3.0f, 0.0f, -2.0f);
	Model* rock3 = new Model(cubeObject, translation, angle, rotation, scale, dimGray);
	addModel(rock3);
}
