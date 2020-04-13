#pragma once

#include "Model.h"
#include "Shader.h"

#include <vector>


class ComplexModel {
public:
	ComplexModel(Shader const &shader);
	~ComplexModel();
	void setTranslation(glm::vec3 translation);
	void setRotation(float angle, glm::vec3 rotation);
	void setScale(glm::vec3 scale);
	void setTransforms(glm::vec3 Translation, float angle, glm::vec3 rotation, glm::vec3 scale);
	void computeModelMatrix();
	virtual void draw();
	virtual void draw(Shader &shader);
	void addModel(Model *model);
private:
	std::vector<Model *> m_Models;
	Shader m_Shader;
	glm::mat4 m_BaseTranslation;
	glm::mat4 m_BaseRotation;
	glm::mat4 m_BaseScale;
	glm::mat4 m_ModelMatrix;
	
};
