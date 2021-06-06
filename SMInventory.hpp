#pragma once
#include "screenMode.hpp"

class SMInventory : public screenMode
{
public:
	SMInventory(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void drawFrame(engine* Engine) override;
	void draw(engine* Engine) override;
};

