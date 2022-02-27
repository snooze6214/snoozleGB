/*
 * snooze6214 2022
 * SPDX-License-Identifier: BSD-2-Clause
 * This file is part of the snoozleGB project
 */

#include "logging.h"

void Logging::init()
{
	spdlog::set_pattern("[%L] %H:%M:%S : %v");
}

void Logging::debug(std::string_view msg)
{
	spdlog::debug(msg);
}

void Logging::info(std::string_view msg)
{
	spdlog::info(msg);
}

void Logging::warn(std::string_view msg)
{
	spdlog::warn(msg);
}

void Logging::error(std::string_view msg)
{
	spdlog::error(msg);
}

void Logging::critical(std::string_view msg)
{
	spdlog::critical(msg);
}

