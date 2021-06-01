#pragma once
#include "eColors.hpp"
class UIManager
{
protected:
	eColor m_color;
	long m_beginX, m_stepsX, m_beginY, m_stepsY;
	long m_padding, m_borderThickness;
public:
	UIManager(const long beginX, const long beginY, const long endX, const long endY, eColor color);
	virtual void drawFrame(class engine* Engine);
	virtual void draw(class engine* Engine) = 0;
};
