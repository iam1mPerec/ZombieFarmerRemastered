#pragma once
#include "eColors.hpp"
class UIElement
{
protected:
	eColors m_color;
	bool m_hasBorder;
	long m_beginX, m_stepsX, m_beginY, m_stepsY;
	long m_padding, m_borderThickness;
public:
	void drawString(class engine* Engine, int index, std::string string);

	UIElement(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	virtual void drawFrame(class engine* Engine);
	virtual void draw(class engine* Engine) = 0;
	virtual void down();
	virtual void up();
	virtual void left();
	virtual void right();
	virtual void submit();
	virtual void quit();
};
