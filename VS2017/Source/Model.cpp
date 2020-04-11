#include "Model.h"

Model::Model(const Object &object)
{
	m_VAO = &object.getVAO();
	m_IndexBuffer = &object.getIndexBuffer();

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

