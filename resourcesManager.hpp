#pragma once
#include "UIElement.hpp"
#include <array>
#include <string>

class resourcesManager : public UIElement
{
	std::array<std::string, 4> m_resourcesNames;
	std::array<int, 4> m_resources;
public:
	resourcesManager(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void draw(class engine* Engine) override;
};
