/*
 * snooze6214 2022
 * SPDX-License-Identifier: BSD-2-Clause
 * This file is part of the snoozleGB project
 */

#pragma once

#include <string_view>
#include <memory>

#include "spdlog/spdlog.h"

class Logging final {
public:
	static void init();
	static void debug(std::string_view msg);
	static void info(std::string_view msg);
	static void warn(std::string_view msg);
	static void error(std::string_view msg);
	static void critical(std::string_view msg);

	template<typename... Args>
	static void debug(std::string_view fmt, Args... args) {
		spdlog::debug(fmt, args...);
	}

	template<typename... Args>
	static void info(std::string_view fmt, Args... args) {
		spdlog::info(fmt, args...);
	}

	template<typename... Args>
	static void warn(std::string_view fmt, Args... args) {
		spdlog::warn(fmt, args...);
	}

	template<typename... Args>
	static void error(std::string_view fmt, Args... args) {
		spdlog::error(fmt, args...);
	}

	template<typename... Args>
	static void critical(std::string_view fmt, Args... args) {
		spdlog::critical(fmt, args...);
	}
};
