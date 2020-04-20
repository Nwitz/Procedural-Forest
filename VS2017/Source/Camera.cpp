#include "Camera.h"
#include "EventManager.h"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <algorithm>

using namespace glm;

Camera::Camera(glm::vec3 position) :  mPosition(position), mLookAt(0.0f, 0.0f, -1.0f), mHorizontalAngle(90.0f), mVerticalAngle(0.0f), mSpeed(2.5f), mAngularSpeed(2.0f)
{
}

Camera::~Camera()
{
}

mat4 Camera::GetProjectionMatrix() const
{
	return perspective(radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(mPosition, mPosition + mLookAt, vec3(0.0f, 1.0f, 0.0f));
}

void Camera::Update(float dt)
{
	/* mouse motion to get the variation in angle */
	mHorizontalAngle -= EventManager::GetMouseMotionX() * mAngularSpeed * dt;
	mVerticalAngle -= EventManager::GetMouseMotionY() * mAngularSpeed * dt;

	mVerticalAngle = std::max(-90.0f, std::min(90.0f, mVerticalAngle));
	if (mHorizontalAngle > 360)
	{
		mHorizontalAngle -= 360;
	}
	else if (mHorizontalAngle < -360)
	{
		mHorizontalAngle += 360;
	}

	float theta = radians(mHorizontalAngle);
	float phi = radians(mVerticalAngle);

	mLookAt = vec3(cosf(phi) * cosf(theta), sinf(phi), -cosf(phi) * sinf(theta));

	vec3 sideVector = glm::cross(mLookAt, vec3(0.0f, 1.0f, 0.0f));
	glm::normalize(sideVector);

	/* WASD movement */
	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
	{
		mPosition += mLookAt * dt * mSpeed;
	}

	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
	{
		mPosition -= mLookAt * dt * mSpeed;
	}

	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
	{
		mPosition += sideVector * dt * mSpeed;
	}

	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
	{
		mPosition -= sideVector * dt * mSpeed;
	}

	// toggle cursor on
	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_N) == GLFW_PRESS)
	{
		glfwSetInputMode(EventManager::GetWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	// toggle cursor off
	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_M) == GLFW_PRESS)
	{
		glfwSetInputMode(EventManager::GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
}
