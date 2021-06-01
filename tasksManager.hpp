#pragma once
#include "UIManager.hpp"

class tasksManager : public UIManager
{
public:
	tasksManager(const long beginX, const long beginY, const long endX, const long endY, eColor color);
	void draw(class engine* Engine) override;
};