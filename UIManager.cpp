#include "UIManager.hpp"
#include "engine.hpp"
#include <iostream>

UIManager::UIManager(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
m_beginX(beginX),
m_beginY(beginY),
m_stepsX(endX - beginX),
m_stepsY(endY - beginY),
m_borderThickness(5),
m_color(color),
m_hasBorder(true),
m_padding(0)
{

}

void UIManager::drawFrame(engine* Engine) {
	Engine->FillRect(m_beginX, m_beginY, m_stepsX, m_stepsY, getColor(m_color));
	if (m_hasBorder) {
		Engine->drawBorder(m_beginX, m_beginY, m_stepsX, m_stepsY, eColors::border, 3);
		Engine->drawBorder(m_beginX, m_beginY, m_stepsX, m_stepsY, eColors::primary, 1);
	}
}
