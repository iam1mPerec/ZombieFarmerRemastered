#include "screenManager.hpp"
#include "engine.hpp"

screenManager::screenManager(const long beginX, const long beginY, const long endX, const long endY, eColor color) :
	UIManager(beginX, beginY, endX, endY, color)
{
	m_padding = 16;
}

void screenManager::draw(engine* Engine) {

}
