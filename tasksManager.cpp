#include <algorithm>
#include "tasksManager.hpp"
#include "engine.hpp"

tasksManager::tasksManager(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
	UIElement(beginX, beginY, endX, endY, color),
	m_maxItems(0)
{
	m_padding = 16;
	m_maxItems = (m_stepsY - m_padding) / (m_padding + engine::charHeight);
}

void tasksManager::draw(engine* Engine) {
	int size = m_items.size();
	int end = std::min(m_maxItems, size);
	for (int i = 0; i < end; i++) {
		Engine->DrawString(m_beginX + m_padding, m_beginY + (m_padding + engine::charHeight)*(i+1), m_items[i]);
	}
}
