#include "SMRoster.hpp"

SMRoster::SMRoster(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
	screenMode(beginX, beginY, endX, endY, color)
{

}

void SMRoster::drawFrame(engine* Engine) {
	Engine->FillRect(m_beginX, m_beginY, m_stepsX, m_stepsY, getColor(m_color));
}

void SMRoster::draw(engine* Engine) {
	drawString(Engine, 0, "roster screen");
}