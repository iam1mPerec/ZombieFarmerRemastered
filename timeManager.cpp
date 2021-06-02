#include "timeManager.hpp"
#include "engine.hpp"

timeManager::timeManager(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
	UIManager(beginX, beginY, endX, endY, color),
	m_time(0),
	m_speed(1),
	m_minutes(0),
	m_hours(12),
	m_days(0)
{
	m_padding = 16;
}

void timeManager::draw(engine* Engine) {
	m_time += Engine->GetElapsedTime() * m_speed;
	m_minutes = m_time;
	std::string minutes, hours;

	if(m_minutes >= 60) {
		m_hours += m_minutes / 60;
		m_minutes %= 60;
		m_time /= 60;
	}
	if (m_hours >= 24) {
		m_days += m_hours / 24;
		m_hours %= 24;
	}

	if (m_minutes < 10) minutes = '0';
	minutes += std::to_string(m_minutes);

	if (m_hours < 10) hours = '0';
	hours += std::to_string(m_hours);

	std::string time = "day:" + std::to_string(m_days) + "   time: " + hours + ":" + minutes;
	
	Engine->DrawString(m_beginX + m_stepsX/2 - time.length()*engine::charWidth, m_beginY + m_stepsY/2 - engine::charHeight/2, time);
}
