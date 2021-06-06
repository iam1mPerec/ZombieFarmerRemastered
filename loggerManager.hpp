#pragma once
#include "UIElement.hpp"

class loggerManager : public UIElement
{
	int m_maxItems;
	std::list<std::string> m_items;
public:
	loggerManager(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void print(std::string time, std::string log);
	void draw(class engine* Engine) override;
};

