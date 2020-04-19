#pragma once

#include <GLFW/glfw3.h>

class EventManager
{
public:
	static void Initialize();
	static void Shutdown();
	static void Update();

	static float GetFrameTime();
	static GLFWwindow* GetWindow();
	static bool CloseWindow();

	static float GetMouseMotionX();
	static float GetMouseMotionY();

	static void EnableMouseCursor();

private:
	// Time
	static double sLastFrameTime;
	static float sFrameTime;

	// Mouse
	static double sLastMousePositionX;
	static float  sMouseDeltaX;
	static double sLastMousePositionY;
	static float  sMouseDeltaY;

	// Window
	static GLFWwindow* spWindow;
};
