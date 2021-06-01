#pragma once
#include "UIManager.hpp"

class loggerManager : public UIManager
{
public:
	loggerManager(const long beginX, const long beginY, const long endX, const long endY, eColor color);
	void draw(class engine* Engine) override;
};

