#include "screenManager.hpp"
#include "screenMode.hpp"
#include "SMMain.hpp"
#include "SMInventory.hpp"
#include "SMRoster.hpp"
#include "engine.hpp"

screenManager::screenManager(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
UIElement(beginX, beginY, endX, endY, color)
{
	m_screenModes[eScreenModes::main] = new SMMain(beginX, beginY, endX, endY, color);
	m_screenModes[eScreenModes::inventory] = new SMInventory(beginX, beginY, endX, endY, color);
	m_screenModes[eScreenModes::roster] = new SMRoster(beginX, beginY, endX, endY, color);
	setMode(eScreenModes::main);
	m_padding = 16;
	m_hasBorder = false;
}

void screenManager::draw(engine* Engine) {
	m_screenMode->draw(Engine);
}

void screenManager::drawFrame(class engine* Engine) {
	m_screenMode->drawFrame(Engine);
}

void screenManager::setMode(eScreenModes mode) {
	m_screenMode = m_screenModes[mode];
}

void screenManager::up() {

}

void screenManager::down() {

}

void screenManager::left() {

}

void screenManager::right() {

}

void screenManager::submit() {

}

void screenManager::quit() {
	setMode(eScreenModes::main);
}

screenManager::~screenManager() {
	for (const auto &[key, value] : m_screenModes) {
		delete value;
	}
}