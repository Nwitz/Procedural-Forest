#pragma once

#include "Object.h"

class Model {

public: 
	Model(const Object &model);
	~Model();
	virtual void draw(const Shader &shader);

private:
	VertexArray *m_VAO;
	IndexBuffer *m_IndexBuffer;

	//TODO: create translation, rotation and scale variables to be used with shader that has a model uniform.
};