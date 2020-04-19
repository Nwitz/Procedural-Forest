#pragma once
#include "Tree1.h"
#include "Tree2.h"
#include "Bush.h"
#include "Bush1.h"
#include "Bush2.h"
#include "Bush3.h"
#include "Rocks.h"
#include "Grass.h"
#include "Object.h"


class LandscapeManager {
public:
	LandscapeManager(float scaleFactor, Object &cube_Object);
	~LandscapeManager();

	ComplexModel* getLargeLandscapeObject(Shader& shader);
	ComplexModel* getMediumLandscapeObject(Shader& shader);

private:
	float m_Scale;
	Object &m_CubeObject;
};
