#include "loggerManager.hpp"
#include "engine.hpp"

loggerManager::loggerManager(const long beginX, const long beginY, const long endX, const long endY, eColor color) :
UIManager(beginX, beginY, endX, endY, color)
{
	m_padding = 16;
}

void loggerManager::draw(engine* Engine) {

}
