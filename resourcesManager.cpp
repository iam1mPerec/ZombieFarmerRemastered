#include "resourcesManager.hpp"
#include "engine.hpp"

resourcesManager::resourcesManager(const long beginX, const long beginY, const long endX, const long endY, eColor color) :
	UIManager(beginX, beginY, endX, endY, color)
{
	m_padding = 16;
}

void resourcesManager::draw(engine* Engine) {

}
