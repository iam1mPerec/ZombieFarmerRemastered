#include "resourcesManager.hpp"
#include "engine.hpp"

resourcesManager::resourcesManager(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
	UIManager(beginX, beginY, endX, endY, color),
	m_resourcesNames({"seeds","food","wood","money" }),
	m_resources({ 10, 20, 30, 45 })
{
	m_padding = 16;
}

void resourcesManager::draw(engine* Engine) {
	for (int i = 0; i < m_resources.size(); i++) {
		Engine->DrawString(m_beginX + m_stepsX/m_resources.size() * i + m_padding, m_beginY + m_stepsY / 2 - engine::charHeight / 2, m_resourcesNames[i] + ": " + std::to_string(m_resources[i]));
	}
}
  