#pragma once

#include "Test.h";
#include "../vendor/imgui/imgui.h"

namespace test {

	test::TestMenu::TestMenu(Test*& currentTestPointer)
		:m_CurrentTest(currentTestPointer)
	{
	
	}

	

	void test::TestMenu::OnImGuiRender()
	{
		for (auto& test : m_Tests) {
			if (ImGui::Button(test.first.c_str())) {
				m_CurrentTest = test.second();
			}
		}
	}
}


