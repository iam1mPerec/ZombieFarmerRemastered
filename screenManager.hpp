#pragma once
#include "UIElement.hpp"
#include <map>
#include "eScreenModes.hpp"

class screenManager : public UIElement
{
	std::map<eScreenModes, class screenMode*> m_screenModes;
	class screenMode* m_screenMode;
public:
	screenManager(const long beginX, const long beginY, const long endX, const long endY, eColors color);
	void draw(class engine* Engine) override;
	void drawFrame(class engine* Engine) override;
	void setMode(eScreenModes mode);
	void up() override;
	void down() override;
	void left() override;
	void right() override;
	void submit() override;
	void quit() override;
	~screenManager();
};
