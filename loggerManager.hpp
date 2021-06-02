#pragma once
#include "UIManager.hpp"

class loggerManager : public UIManager
{
	int m_maxItems;
	std::vector<std::string> m_items;
public:
	loggerManager(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void draw(class engine* Engine) override;
};

