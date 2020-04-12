#include "Model.h"

Model::Model(const Object& object)
{
	m_VAO = &object.getVAO();
	m_IndexBuffer = &object.getIndexBuffer();

	m_RelativeTranslation = glm::mat4(1.0f);
	m_RelativeRotation = glm::mat4(1.0f);
	m_RelativeScale = glm::mat4(1.0f);
	m_ModelMatrix = glm::mat4(1.0f);
}

Model::Model(const Object& object, glm::vec3 translation, float angle, glm::vec3 rotation, glm::vec3 scale)
	: m_RelativeTranslation(glm::translate(glm::mat4(1.0f), translation)),
	m_RelativeRotation(glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotation)),
	m_RelativeScale(glm::scale(glm::mat4(1.0f), scale))
{
	m_VAO = &object.getVAO();
	m_IndexBuffer = &object.getIndexBuffer();
	m_ModelMatrix = glm::mat4(1.0f);
}

Model::~Model()
{
	m_VAO = nullptr;
	m_IndexBuffer = nullptr;
}

void Model::draw(const Shader &shader)
{
	Renderer renderer;
	renderer.Draw(*m_VAO, *m_IndexBuffer, shader);
}

void Model::setTranslation(glm::vec3 translation)
{
	m_RelativeTranslation = glm::translate(glm::mat4(1.0f), translation);
}

void Model::setRotation(float angle, glm::vec3 rotation)
{
	m_RelativeRotation = glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotation);
}

void Model::setScale(glm::vec3 scale)
{
	m_RelativeScale = glm::scale(glm::mat4(1.0f), scale);
}

void Model::computeModelMatrix()
{
	m_ModelMatrix = m_RelativeTranslation * m_RelativeRotation * m_RelativeScale;
}

glm::mat4 Model::getModelMatrix()
{
	return m_ModelMatrix;
}
