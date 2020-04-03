#pragma once

#include "../Renderer.h"
#include "../vendor/imgui/imgui.h"

namespace test {

	class Test
	{
	public: 
		Test() {}
		virtual ~Test() {}

		virtual void OnUpdate(float dektaTune) {}
		virtual void OnRender() {}
		virtual void OnImGuiRender() {}
	};


}