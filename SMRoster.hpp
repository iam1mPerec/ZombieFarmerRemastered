#pragma once
#include "screenMode.hpp"

class SMRoster : public screenMode
{
public:
	SMRoster(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void drawFrame(engine* Engine) override;
	void draw(engine* Engine) override;
};
