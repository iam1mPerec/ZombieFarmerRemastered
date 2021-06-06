#pragma once
#include "UIElement.hpp"

class screenMode : public UIElement
{
public:
	screenMode(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	virtual void draw(class engine* Engine) = 0;
	virtual void drawFrame(class engine* Engine) = 0;
};