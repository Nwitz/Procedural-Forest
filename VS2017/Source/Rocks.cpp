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

	float initialX = 0;
	float initialY = 0;
	float initialZ = 0;

	float height = 1.0;
	float width = 1.0;

	scale = glm::vec3(width * 0.3f, height * 0.2f, width * 0.3f);
	translation = glm::vec3(initialX, initialY, initialZ);
	Model* rock1 = new Model(cubeObject, translation, angle, rotation, scale, dimGray);
	addModel(rock1);

	scale = glm::vec3(width * 0.2f, height * 0.05f, width * 0.2f);
	translation = glm::vec3(initialX , initialY + 1.0f, initialZ);
	Model* rock2 = new Model(cubeObject, translation, angle, rotation, scale, dimGray);
	addModel(rock2);

	scale = glm::vec3(width * 0.2f, height * 0.1f, width * 0.25f);
	translation = glm::vec3(initialX + 3.0f, initialY, initialZ -2.0f);
	Model* rock3 = new Model(cubeObject, translation, angle, rotation, scale, dimGray);
	addModel(rock3);
}
