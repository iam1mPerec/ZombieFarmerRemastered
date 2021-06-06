#pragma once
#include "screenMode.hpp"
class SMMain : public screenMode
{
public:
	SMMain(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void drawFrame(engine* Engine) override;
	void draw(engine* Engine) override;
};

