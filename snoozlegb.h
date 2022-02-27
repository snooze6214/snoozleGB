/*
 * snooze6214 2022
 * SPDX-License-Identifier: BSD-2-Clause
 * This file is part of the snoozleGB project
 */

#pragma once

#include "gui.h"

class SnoozleGB {
public:
	SnoozleGB();
	~SnoozleGB();
	int run();

private:
	GUI m_gui;
	bool m_is_running = true;
};
