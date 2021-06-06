#include "SMMain.hpp"

SMMain::SMMain(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
screenMode(beginX, beginY, endX, endY, color)
{
	m_padding = 16;
}

void SMMain::drawFrame(engine* Engine) {
	Engine->FillRect(m_beginX, m_beginY, m_stepsX, m_stepsY, getColor(m_color));
}

void SMMain::draw(engine* Engine) {
	drawString(Engine, 0, "main screen");
}
