#pragma once

#include "Object.h"
#include "vendor/obj_loader/OBJloaderV2.h"

Object::Object(std::string path)
{
	std::vector<unsigned int> vertexIndices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> UVs;

	loadOBJ2(path.c_str(), vertexIndices, vertices, normals, UVs);

	m_VAO = std::make_unique<VertexArray>();

	m_PositionVBO = std::make_unique<VertexBuffer>(&vertices[0],vertices.size() * sizeof(glm::vec3));
	VertexBufferLayout positionLayout;
	positionLayout.Push<float>(3);
	m_VAO->AddBuffer(*m_PositionVBO, positionLayout);

	m_NormalVBO = std::make_unique<VertexBuffer>(&normals[0], normals.size() * sizeof(glm::vec3));
	VertexBufferLayout normalLayout;
	normalLayout.Push<float>(3);
	m_VAO->AddBuffer(*m_NormalVBO, normalLayout);

	m_TexturePosVBO = std::make_unique<VertexBuffer>(&UVs[0], UVs.size() * sizeof(glm::vec2));
	VertexBufferLayout textureLayout;
	textureLayout.Push<float>(2);
	m_VAO->AddBuffer(*m_TexturePosVBO, textureLayout);

	m_IndexBuffer = std::make_unique<IndexBuffer>(&vertexIndices[0], vertexIndices.size());
}

Object::~Object()
{
}

VertexArray& Object::getVAO() const
{
	return *m_VAO;
}

IndexBuffer& Object::getIndexBuffer() const
{
	return *m_IndexBuffer;
}

