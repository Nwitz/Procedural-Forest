#pragma once

#include "Object.h"

class Model {

public: 
	Model(const Object &object);
	Model(const Object& object, glm::vec3 translation, float angle, glm::vec3 rotaiton, glm::vec3 scale);
	~Model();
	virtual void draw(const Shader &shader);
	void setTranslation(glm::vec3 translation);
	void setRotation(float angle, glm::vec3 rotation);
	void setScale(glm::vec3 scale);
	void computeModelMatrix();
	glm::mat4 getModelMatrix();

private:
	VertexArray *m_VAO;
	IndexBuffer *m_IndexBuffer;
	glm::mat4 m_RelativeTranslation;
	glm::mat4 m_RelativeRotation;
	glm::mat4 m_RelativeScale;
	glm::mat4 m_ModelMatrix;
};