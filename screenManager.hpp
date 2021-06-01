#pragma once
#include "UIManager.hpp"

class screenManager : public UIManager
{
public:
	screenManager(const long beginX, const long beginY, const long endX, const long endY, eColor color);
	void draw(class engine* Engine) override;
};
