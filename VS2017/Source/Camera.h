#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
	Camera(glm::vec3 position);
	~Camera();
	glm::mat4 GetViewMatrix() const;
	virtual glm::mat4 GetProjectionMatrix() const;
	void Update(float dt);

private:
	glm::vec3 mPosition;
	glm::vec3 mLookAt;

	float mHorizontalAngle;
	float mVerticalAngle;

	float mSpeed;
	float mAngularSpeed;
};
