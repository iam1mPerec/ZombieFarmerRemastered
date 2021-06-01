#include "timeManager.hpp"
#include "engine.hpp"

timeManager::timeManager(const long beginX, const long beginY, const long endX, const long endY, eColor color) :
	UIManager(beginX, beginY, endX, endY, color)
{
	m_padding = 16;
}

void timeManager::draw(engine* Engine) {

}
