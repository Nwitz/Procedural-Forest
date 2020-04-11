#pragma once

#include "Object.h"
#include "vendor/obj_loader/OBJloader.h"
#include "vendor/obj_loader/vboindexer.hpp"

Object::Object()
{
}

Object::Object(std::string path)
{
	std::vector<unsigned short> vertexIndices;
	std::vector<glm::vec3> positions, intermediate_positions;
	std::vector<glm::vec2> uvs, intermediate_uvs;
	std::vector<glm::vec3> normals, intermediate_normals;

	loadOBJ(path.c_str(), intermediate_positions, intermediate_normals, intermediate_uvs);

	indexVBO(intermediate_positions, intermediate_uvs, intermediate_normals,
		vertexIndices, positions, uvs, normals);

	m_VAO = std::make_unique<VertexArray>();

	m_PositionVBO = std::make_unique<VertexBuffer>(&positions.front(), positions.size() * sizeof(glm::vec3));
	VertexBufferLayout positionLayout;
	positionLayout.Push<float>(3);
	m_VAO->AddBuffer(*m_PositionVBO, positionLayout);

	m_TexturePosVBO = std::make_unique<VertexBuffer>(&uvs.front(), uvs.size() * sizeof(glm::vec2));
	VertexBufferLayout textureLayout;
	textureLayout.Push<float>(2);
	m_VAO->AddBuffer(*m_TexturePosVBO, textureLayout);

	m_NormalVBO = std::make_unique<VertexBuffer>(&normals.front(), normals.size() * sizeof(glm::vec3));
	VertexBufferLayout normalLayout;
	normalLayout.Push<float>(3);
	m_VAO->AddBuffer(*m_NormalVBO, normalLayout);

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
