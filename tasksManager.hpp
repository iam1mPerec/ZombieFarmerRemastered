#pragma once
#include <string>
#include <vector>
#include "UIElement.hpp"


class tasksManager : public UIElement
{
	int m_maxItems;
	std::vector<std::string> m_items;
public:
	tasksManager(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void draw(class engine* Engine) override;
};