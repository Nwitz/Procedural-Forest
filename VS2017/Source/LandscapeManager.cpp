#include "LandscapeManager.h"
#include "Shader.h"



LandscapeManager::LandscapeManager(float scaleFactor, Object &cube_Object)
	:m_Scale(scaleFactor), m_CubeObject(cube_Object)
{
}

LandscapeManager::~LandscapeManager()
{

}

// Assumes random has been set
ComplexModel* LandscapeManager::getLargeLandscapeObject(Shader &shader)
{
	ComplexModel* complexModel;
	if (rand() % 100 < 50) {
		complexModel = new Tree1(shader, m_CubeObject);
		complexModel->setScale(glm::vec3(m_Scale));
	}
	else {
		complexModel = new Tree2(shader, m_CubeObject);
		complexModel->setScale(glm::vec3(m_Scale));
	}

	return complexModel;
}

ComplexModel* LandscapeManager::getMediumLandscapeObject(Shader& shader)
{
	int roll = rand() % 100;
	ComplexModel* complexModel;

	if (roll < 20) {
		complexModel = new Bush(shader, m_CubeObject);
	}
	else if (roll < 40) {
		complexModel = new Bush1(shader, m_CubeObject);
	}
	else if (roll < 60) {
		complexModel = new Bush2(shader, m_CubeObject);
	}
	else if (roll < 80) {
		complexModel = new Bush3(shader, m_CubeObject);
	}
	else {
		complexModel = new Rocks(shader, m_CubeObject);
	}
	complexModel->setScale(glm::vec3(m_Scale));

	return complexModel;
}
