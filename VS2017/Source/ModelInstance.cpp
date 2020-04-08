#include "ModelInstance.h"

ModelInstance::ModelInstance(const Model &model)
{
	m_VAO = &model.getVAO();
	m_IndexBuffer = &model.getIndexBuffer();

}

ModelInstance::~ModelInstance()
{
	m_VAO = nullptr;
	m_IndexBuffer = nullptr;
}

void ModelInstance::draw(const Shader &shader)
{
	Renderer renderer;
	renderer.Draw(*m_VAO, *m_IndexBuffer, shader);
}
