#include "tasksManager.hpp"
#include "engine.hpp"

tasksManager::tasksManager(const long beginX, const long beginY, const long endX, const long endY, eColor color) :
	UIManager(beginX, beginY, endX, endY, color)
{
	m_padding = 16;
}

void tasksManager::draw(engine* Engine) {

}
