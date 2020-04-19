#include "EventManager.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

double EventManager::sLastFrameTime = glfwGetTime();
float  EventManager::sFrameTime = 0.0f;

double EventManager::sLastMousePositionX = 0.0f;
float  EventManager::sMouseDeltaX = 0.0f;
double EventManager::sLastMousePositionY = 0.0f;
float  EventManager::sMouseDeltaY = 0.0f;

GLFWwindow* EventManager::spWindow = nullptr;

void EventManager::Initialize()
{
	/* initialize GLFW */
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		exit(-1);
	}

	spWindow = glfwCreateWindow(1000, 1000, "Procedural Forest", NULL, NULL);

	if (spWindow == nullptr)
	{
		glfwTerminate();
		exit(-1);
	}

	/* make the window's context current */
	glfwMakeContextCurrent(spWindow);

	/* limit frame rate */
	glfwSwapInterval(1);

	/* initial mouse position */
	glfwPollEvents();
	double x, y;
	glfwGetCursorPos(spWindow, &x, &y);

	sLastMousePositionX = x;
	sLastMousePositionY = y;

	/* initial time */
	sLastFrameTime = glfwGetTime();
	srand((unsigned int)time(nullptr));
}

void EventManager::Shutdown()
{
	glfwTerminate();
	spWindow = nullptr;
}

void EventManager::Update()
{
	glfwPollEvents();

	/* update mouse position */
	double x, y;
	glfwGetCursorPos(spWindow, &x, &y);
	sMouseDeltaX = static_cast<float>(x - sLastMousePositionX);
	sMouseDeltaY = static_cast<float>(y - sLastMousePositionY);
	sLastMousePositionX = x;
	sLastMousePositionY = y;

	/* update frame time */
	double currentTime = glfwGetTime();
	sFrameTime = static_cast<float>(currentTime - sLastFrameTime);
	sLastFrameTime = currentTime;
}

float EventManager::GetFrameTime()
{
	return sFrameTime;
}

GLFWwindow* EventManager::GetWindow()
{
	return spWindow;
}

bool EventManager::CloseWindow()
{
	return glfwGetKey(spWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(spWindow);
}

float EventManager::GetMouseMotionX()
{
	return sMouseDeltaX;
}

float EventManager::GetMouseMotionY()
{
	return sMouseDeltaY;
}

void EventManager::EnableMouseCursor()
{
	glfwSetInputMode(spWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}