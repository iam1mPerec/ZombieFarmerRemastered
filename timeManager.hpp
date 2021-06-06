#pragma once
#include "UIElement.hpp"
#include <tuple>
#include <string>

class timeManager : public UIElement
{
	float m_time, m_speed;
	int m_days, m_hours, m_minutes;
public:
	timeManager(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void draw(class engine* Engine) override;
	std::tuple<int, int, int> getTime() const;
	std::string getTimeStamp() const;
	static std::string dateFormat(int num);
};
