#pragma once
#include "UIManager.hpp"

class resourcesManager : public UIManager
{
public:
	resourcesManager(const long beginX, const long beginY, const long endX, const long endY, eColor color);
	void draw(class engine* Engine) override;
};
