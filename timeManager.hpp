#pragma once
#include "UIManager.hpp"

class timeManager : public UIManager
{
public:
	timeManager(const long beginX, const long beginY, const long endX, const long endY, eColor color);
	void draw(class engine* Engine) override;
};
