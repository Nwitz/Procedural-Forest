#pragma once

#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "glm/gtc/matrix_transform.hpp"


#include <memory>

class Object {
public:
	Object(std::string path);
	~Object();
	VertexArray &getVAO() const;
	IndexBuffer &getIndexBuffer() const;

private:
	std::unique_ptr<VertexArray> m_VAO;
	std::unique_ptr<VertexBuffer> m_PositionVBO;
	std::unique_ptr<VertexBuffer> m_NormalVBO;
	std::unique_ptr<VertexBuffer> m_TexturePosVBO;
	std::unique_ptr<IndexBuffer> m_IndexBuffer;
	std::unique_ptr<Shader> m_Shader;

};
