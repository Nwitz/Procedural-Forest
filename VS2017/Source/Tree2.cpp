#include "Tree2.h"

Tree2::Tree2(const Shader& shader, Object& cubeObject) : ComplexModel(shader)
{
	shader.Bind();

	glm::vec3 translation(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation(1.0f, 1.0f, 1.0f);
	float angle = 0.0f;
	glm::vec3 scale(0.5f, 0.5f, 0.5f);
	glm::vec4 green(0.3f, 0.8f, 0.1f, 1.0f);
	glm::vec4 yellow(0.8f, 0.7f, 0.0f, 1.0f);
	glm::vec4 brown(0.545f, 0.271f, 0.075f, 1.0f);
	glm::vec4 forestGreen(0.333f, 0.420f, 0.184f, 1.0f);

	float offset = 20.0f; // used to center objects 

	scale = glm::vec3(0.3f, 4.0f, 0.3f);
	translation = glm::vec3(0.0f, offset, 0.0f);
	Model* trunk = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunk);

	scale = glm::vec3(0.2f, 4.0f, 0.1f);
	translation = glm::vec3(0.0f, offset, 1.5f);
	Model* trunkSide1 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide1);

	translation = glm::vec3(0.0f, offset, -1.5f);
	Model* trunkSide2 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide2);

	scale = glm::vec3(0.1f, 4.0f, 0.2f);
	translation = glm::vec3(-1.5f, offset, 0.0f);
	Model* trunkSide3 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide3);

	translation = glm::vec3(1.5f, offset, 0.0f);
	Model* trunkSide4 = new Model(cubeObject, translation, angle, rotation, scale, brown);
	addModel(trunkSide4);

	scale = glm::vec3(0.5f, 0.25f, 2.5f);
	translation = glm::vec3(0.0f, offset -7.0f, 0.0f);
	Model* leaves = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves);

	scale = glm::vec3(2.5f, 0.25f, 0.5f);
	translation = glm::vec3(0.0f, offset -7.0f, 0.0f);
	Model* leaves2 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves2);

	scale = glm::vec3(0.5f, 0.25f, 2.25f);
	translation = glm::vec3(0.0f, offset -3.0f, 0.0f);
	Model* leaves3 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves3);

	scale = glm::vec3(2.25f, 0.25f, 0.5f);
	translation = glm::vec3(0.0f, offset -3.0f, 0.0f);
	Model* leaves4 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves4);

	scale = glm::vec3(0.5f, 0.25f, 2.0f);
	translation = glm::vec3(0.0f, offset + 1.0f, 0.0f);
	Model* leaves5 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves5);

	scale = glm::vec3(2.0f, 0.25f, 0.5f);
	translation = glm::vec3(0.0f, offset + 1.0f, 0.0f);
	Model* leaves6 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves6);

	scale = glm::vec3(0.5f, 0.25f, 1.75f);
	translation = glm::vec3(0.0f, offset + 5.0f, 0.0f);
	Model* leaves7 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves7);

	scale = glm::vec3(1.75f, 0.25f, 0.5f);
	translation = glm::vec3(0.0f, offset +5.0f, 0.0f);
	Model* leaves8 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves8);

	scale = glm::vec3(0.5f, 0.25f, 1.5f);
	translation = glm::vec3(0.0f, offset + 9.0f, 0.0f);
	Model* leaves9 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves9);

	scale = glm::vec3(1.5f, 0.25f, 0.5f);
	translation = glm::vec3(0.0f, offset + 9.0f, 0.0f);
	Model* leaves10 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves10);
	
	scale = glm::vec3(0.5f, 0.25f, 1.25f);
	translation = glm::vec3(0.0f, offset + 13.0f, 0.0f);
	Model* leaves11 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves11);

	scale = glm::vec3(1.25f, 0.25f, 0.5f);
	translation = glm::vec3(0.0f, offset + 13.0f, 0.0f);
	Model* leaves12 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves12);

	scale = glm::vec3(0.5f, 0.25f, 1.0f);
	translation = glm::vec3(0.0f, offset + 17.0f, 0.0f);
	Model* leaves13 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves13);

	scale = glm::vec3(1.0f, 0.25f, 0.5f);
	translation = glm::vec3(0.0f, offset + 17.0f, 0.0f);
	Model* leaves14 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves14);

	scale = glm::vec3(0.5f, 0.25f, 0.75f);
	translation = glm::vec3(0.0f, offset + 21.0f, 0.0f);
	Model* leaves15 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves15);

	scale = glm::vec3(0.75f, 0.25f, 0.5f);
	translation = glm::vec3(0.0f, offset + 21.0f, 0.0f);
	Model* leaves16 = new Model(cubeObject, translation, angle, rotation, scale, forestGreen);
	addModel(leaves16);

}
