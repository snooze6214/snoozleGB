/*
 * snooze6214 2022
 * SPDX-License-Identifier: BSD-2-Clause
 * This file is part of the snoozleGB project
 */

#pragma once

#include "GLFW/glfw3.h"

#include <memory>
#include <functional>

class GUI {
public:
	GUI();
	~GUI();
	void poll_events();
	void render();

	std::function<void(void)> on_close_callback;

private:
	void init_glfw();
	void init_imgui();

	GLFWwindow* m_window = nullptr;
};
