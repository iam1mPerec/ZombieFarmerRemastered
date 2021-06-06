#include "timeManager.hpp"
#include "engine.hpp"

timeManager::timeManager(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
	UIElement(beginX, beginY, endX, endY, color),
	m_time(0),
	m_speed(1),
	m_days(0),
	m_hours(12),
	m_minutes(0)
{
	m_padding = 16;
}

void timeManager::draw(engine* Engine) {
	m_time += Engine->GetElapsedTime() * m_speed;
	m_minutes = m_time;

	if(m_minutes >= 60) {
		m_hours += m_minutes / 60;
		m_minutes %= 60;
		m_time /= 60;
	}
	if (m_hours >= 24) {
		m_days += m_hours / 24;
		m_hours %= 24;
	}

	std::string minutes = dateFormat(m_minutes);
	std::string hours = dateFormat(m_hours);

	std::string time = "day:" + std::to_string(m_days) + "   time: " + hours + ":" + minutes;
	
	Engine->DrawString(m_beginX + m_stepsX/2 - time.length()*engine::charWidth, m_beginY + m_stepsY/2 - engine::charHeight/2, time);
}

std::tuple<int, int, int> timeManager::getTime() const {
	return { m_days, m_hours, m_minutes };
}

std::string timeManager::getTimeStamp() const {
	return "day:" + std::to_string(m_days) + " " + dateFormat(m_hours) + ":" + dateFormat(m_minutes);
}

std::string timeManager::dateFormat(int num) {
	std::string result = "";
	if (num < 10) result = "0";
	return result + std::to_string(num);
}