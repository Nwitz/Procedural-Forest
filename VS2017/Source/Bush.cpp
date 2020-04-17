#include "Bush.h"

Bush::Bush(const Shader& shader, Object& cubeObject) : ComplexModel(shader)
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
	glm::vec4 forestGreen(0.333f, 0.420f, 0.184f, 1.0f);

	scale = glm::vec3(0.3f, 0.3f, 0.3f);
	translation = glm::vec3(0.0f, 0.0f, 0.0f);
	Model* trunk = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunk);

	scale = glm::vec3(0.2f, 0.3f, 0.1f);
	translation = glm::vec3(0.0f, 0.0f, 1.5f);
	Model* trunkSide1 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide1);

	translation = glm::vec3(0.0f, 0.0f, -1.5f);
	Model* trunkSide2 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide2);

	scale = glm::vec3(0.1f, 0.3f, 0.2f);
	translation = glm::vec3(-1.5f, 0.0f, 0.0f);
	Model* trunkSide3 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide3);

	translation = glm::vec3(1.5f, 0.0f, 0.0f);
	Model* trunkSide4 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide4);
	
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
	translation = glm::vec3(0.0f, 6.5f, 0.0f);
	Model* leaves = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves);

	scale = glm::vec3(0.8f, 0.3f, 0.8f);
	translation = glm::vec3(0.0f, 12.0f, 0.0f);
	Model* leavesTop = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leavesTop);

	scale = glm::vec3(0.7f, 0.7f, 0.2f);
	translation = glm::vec3(0.0f, 6.5f, 5.0f);
	Model* leavesSide1 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leavesSide1);
	
	translation = glm::vec3(0.0f, 6.5f, -5.0f);
	Model* leavesSide2 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leavesSide2);

	scale = glm::vec3(0.2f, 0.7f, 0.7f);
	translation = glm::vec3(5.0, 6.5f, 0.0f);
	Model* leavesSide3 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leavesSide3);

	translation = glm::vec3(-5.0, 6.5f, 0.0f);
	Model* leavesSide4 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leavesSide4);

	/*
	translation = glm::vec3(0.0f, 16.0f, -8.0f);
	Model* leavesSide2 = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(leavesSide2);

	scale = glm::vec3(0.3f, 0.8f, 1.3f);
	translation = glm::vec3(8.0f, 16.0f, 0.0f);
	Model* leavesSide3 = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(leavesSide3);

	translation = glm::vec3(-8.0f, 16.0f, 0.0f);
	Model* leavesSide4 = new Model(cubeObject, translation, angle, rotation, scale, green);
	addModel(leavesSide4);
	*/
}
