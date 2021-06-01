#include "GMMain.hpp"
#include "engine.hpp"
#include "eColors.hpp"
#include <iostream>

GMMain::GMMain(const int maxWidth, const int maxHeight) :
    gameMode(maxWidth, maxHeight),
    m_resourcesManager(0, 0, maxWidth - maxWidth/5, 25, eColor::primary),
    m_timeManager(maxWidth - maxWidth/5, 0, maxWidth, 25, eColor::primary),
    m_screenManager(0, 25, maxWidth - maxWidth/5, maxHeight - maxHeight / 4, eColor::font_disabled_selected),
    m_tasksManager(maxWidth - maxWidth/5, 25, maxWidth, maxHeight - maxHeight / 4, eColor::secondary),
    m_loggerManager(0, maxHeight - maxHeight/4, maxWidth, maxHeight, eColor::secondary),
    m_menuMenager(maxWidth - maxWidth/5, maxHeight - maxHeight/4, maxWidth, maxHeight, eColor::background)
{
}

void GMMain::DrawFrame(engine* Engine) {
    auto LBackground = Engine->CreateLayer();
    Engine->SetDrawTarget(LBackground);

    m_resourcesManager.drawFrame(Engine);
    m_timeManager.drawFrame(Engine);
    m_screenManager.drawFrame(Engine);
    m_tasksManager.drawFrame(Engine);
    m_loggerManager.drawFrame(Engine);
    m_menuMenager.drawFrame(Engine);
    
    Engine->EnableLayer(LBackground, true);
    Engine->SetDrawTarget(nullptr);
}

void GMMain::Draw(engine* Engine) {
    Engine->Clear(olc::BLANK);
}

void GMMain::submit() {}
void GMMain::quit() {}
void GMMain::up() {}
void GMMain::down() {}
void GMMain::left() {}
void GMMain::right() {}

GMMain::~GMMain() {

}