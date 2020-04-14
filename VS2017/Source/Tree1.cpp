#include "Tree1.h"

Tree1::Tree1(const Shader& shader, Object& cubeObject) : ComplexModel(shader)
{
	shader.Bind();


	// 4 cube base with single cube on top
	glm::vec3 translation(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation(1.0f, 1.0f, 1.0f);
	float angle = 0.0f;
	glm::vec3 scale(0.5f, 0.5f, 0.5f);
	glm::vec4 green(0.3f, 0.8f, 0.1f, 1.0f);
	glm::vec4 yellow(0.8f, 0.7f, 0.0f, 1.0f);
	glm::vec4 brown(0.545f, 0.271f, 0.075f, 1.0f);
	
	float initialX = 0;
	float initialY = 0;
	float initialZ = 0;

	float height = 1.0;
	float width = 1.0;

	scale = glm::vec3(width * 0.5f, height * 3.0f, width* 0.5f);
	translation = glm::vec3(initialX, initialY, initialZ);
	Model* trunk = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunk);

	scale = glm::vec3(width * 0.3f, height * 3.0f, width * 0.12f);
	translation = glm::vec3(initialX, initialY, initialZ);
	Model* trunkSide1 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide1);

	translation = glm::vec3(initialX, initialY, initialZ - 2.5f);
	Model* trunkSide2 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide2);

	scale = glm::vec3(width * 0.12f, height * 3.0f, width * 0.3f);
	translation = glm::vec3(initialX - 2.5f, initialY, initialZ);
	Model* trunkSide3 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide3);

	translation = glm::vec3(initialX + 2.5f, initialY, initialZ);
	Model* trunkSide4 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide4);

	scale = glm::vec3(width * 1.5f, height* 1.0f, width * 1.5f);
	translation = glm::vec3(initialX, initialY + 16.0f, initialZ);
	Model* leaves = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(leaves);

	scale = glm::vec3(width * 1.2f, height * 0.3f, width * 1.2f);
	translation = glm::vec3(initialX, initialY + 22.0f, initialZ);
	Model* leavesTop = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(leavesTop);

	scale = glm::vec3(width * 1.3f, height * 0.8f, width * 0.3f);
	translation = glm::vec3(initialX, initialY + 16.0f, initialZ + 8.0f);
	Model* leavesSide1 = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(leavesSide1);

	translation = glm::vec3(initialX, initialY + 16.0f, initialZ -8.0f);
	Model* leavesSide2 = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(leavesSide2);

	scale = glm::vec3(width * 0.3f, height * 0.8f, width * 1.3f);
	translation = glm::vec3(initialX + 8.0f, initialY + 16.0f, initialZ);
	Model* leavesSide3 = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(leavesSide3);

	translation = glm::vec3(initialX - 8.0f, initialY + 16.0f, initialZ);
	Model* leavesSide4 = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(leavesSide4);
}
