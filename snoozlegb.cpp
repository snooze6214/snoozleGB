/*
 * snooze6214 2022
 * SPDX-License-Identifier: BSD-2-Clause
 * This file is part of the snoozleGB project
 */

#include "snoozlegb.h"
#include "logging.h"

SnoozleGB::SnoozleGB() 
{
	Logging::init();
	m_gui.on_close_callback = [&]() {
		m_is_running = false;
	};
}

SnoozleGB::~SnoozleGB()
{

}

int SnoozleGB::run()
{
	while (m_is_running) {
		m_gui.poll_events();
		m_gui.render();
	}

	return 0;
}
