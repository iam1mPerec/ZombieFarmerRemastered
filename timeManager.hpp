#pragma once
#include "UIManager.hpp"

class timeManager : public UIManager
{
	float m_time, m_speed;
	int m_days, m_minutes, m_hours;
public:
	timeManager(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void draw(class engine* Engine) override;
};
