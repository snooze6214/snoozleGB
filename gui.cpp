/*
 * snooze6214 2022
 * SPDX-License-Identifier: BSD-2-Clause
 * This file is part of the snoozleGB project
 */

#include "gui.h"

#include <stdexcept>

#include "logging.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

GUI::GUI()
{
	glfwSetErrorCallback([](int error_code, const char* msg) {
		Logging::critical("GLFW ERROR {0} : {1}", error_code, msg);
	});
	
	init_glfw();
	init_imgui();
}

GUI::~GUI()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void GUI::poll_events()
{
	glfwPollEvents();
	if (glfwWindowShouldClose(m_window) && on_close_callback)
		on_close_callback();
		
}

void GUI::render()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	
	ImGui::ShowDemoWindow();

	ImGui::Render();

	int fb_width, fb_height;
	glfwGetFramebufferSize(m_window, &fb_width, &fb_height);
	glViewport(0, 0, fb_width, fb_height);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}

	glfwSwapBuffers(m_window);
}

void GUI::init_glfw()
{
	if (!glfwInit()) {
		Logging::critical(__FILE__ " : GLFW failed to initialize");
		throw std::runtime_error("GLFW failed to initialize");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	m_window = glfwCreateWindow(800, 800, "Hello world", NULL, NULL);
	if (!m_window) {
		Logging::critical(__FILE__ " : Failed to create new window");
		throw std::runtime_error("Failed to create new window");
	}
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);
}

void GUI::init_imgui()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& imgui_io = ImGui::GetIO();
	imgui_io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	imgui_io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	imgui_io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	ImGui::StyleColorsLight();

	ImGuiStyle& imgui_style = ImGui::GetStyle();
	if (imgui_io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		imgui_style.WindowRounding = 0.0f;
		imgui_style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	};

	ImGui_ImplGlfw_InitForOpenGL(m_window, true);
	ImGui_ImplOpenGL3_Init("#version 130");
}
