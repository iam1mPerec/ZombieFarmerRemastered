#include "loggerManager.hpp"
#include "engine.hpp"

loggerManager::loggerManager(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
UIElement(beginX, beginY, endX, endY, color),
m_maxItems(0)
{
	m_padding = 16;
	m_maxItems = (m_stepsY - m_padding) / (m_padding + engine::charHeight);
}

//TODO: when implementing append insure that container size is not greater m_maxItems

void loggerManager::print(std::string time, std::string log) {
	m_items.push_back(time + "\t\t\t" + log);
	if (m_items.size() > m_maxItems) m_items.pop_front();
}

void loggerManager::draw(engine* Engine) {
	int size = m_items.size();
	int end = std::min(m_maxItems, size);
	int start = end == size ? 0 : size - end;
	int i = 0;
	for (auto item : m_items) {
		drawString(Engine, i++, item);
	}
}
