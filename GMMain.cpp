#include "GMMain.hpp"
#include "engine.hpp"
#include "eColors.hpp"
#include <iostream>

GMMain::GMMain(const int maxWidth, const int maxHeight) :
    gameMode(maxWidth, maxHeight),
    m_resourcesManager(0, 0, maxWidth - maxWidth/5, 25, eColors::primary),
    m_timeManager(maxWidth - maxWidth/5, 0, maxWidth, 25, eColors::primary),
    m_screenManager(0, 25, maxWidth - maxWidth/5, maxHeight - maxHeight / 4, eColors::font_disabled_selected),
    m_tasksManager(maxWidth - maxWidth/5, 25, maxWidth, maxHeight - maxHeight / 4, eColors::secondary),
    m_loggerManager(0, maxHeight - maxHeight/4, maxWidth - maxWidth/5, maxHeight, eColors::secondary),
    m_menuManager(maxWidth - maxWidth/5, maxHeight - maxHeight/4, maxWidth, maxHeight, eColors::background)
{
    menu MENU;
    MENU["Planting"];

    MENU["Planting"]["Potatos"];
    MENU["Planting"]["Corn"];
    MENU["Planting"]["Tomatos"];
    MENU["Planting"]["Carrots"];
    MENU["Planting"]["Pumpkins"];
    MENU["Planting"]["Cherry"];

    MENU["Building"];

    MENU["Building"]["Fence"];
    MENU["Building"]["Tunel"];
    MENU["Building"]["House"];
    MENU["Building"]["Tent"];
    MENU["Building"]["Barracks"];
        
    MENU["Activities"];

    MENU["Activities"]["Chop"];
    MENU["Activities"]["Scavange"];
    MENU["Activities"]["Collect"];
    MENU["Activities"]["Shop"];

    MENU["Activities"]["Shop"]["Buy"];

    MENU["Activities"]["Shop"]["Buy"]["Wood"];
    MENU["Activities"]["Shop"]["Buy"]["Seeds"];
    MENU["Activities"]["Shop"]["Buy"]["Food"];

    MENU["Activities"]["Shop"]["Sell"];

    MENU["Activities"]["Shop"]["Sell"]["Wood"];
    MENU["Activities"]["Shop"]["Sell"]["Seeds"];
    MENU["Activities"]["Shop"]["Sell"]["Food"];

    MENU["Activities"]["Shop"]["Hire Farmers"];

    MENU["Troops"];
    
    MENU["Troops"]["Attack"];
    MENU["Troops"]["Skills"];
    MENU["Troops"]["Items"];
    MENU["Troops"]["Protect"];
    MENU["Troops"]["Feed"];
    
    MENU["Save"];

    MENU["Save"]["slot 1"];
    MENU["Save"]["slot 2"];
    MENU["Save"]["slot 3"];
        
    MENU["Exit"];
    
    MENU["Exit"]["Yes"];
    MENU["Exit"]["No"];

    m_menuManager.setMenu(std::move(MENU));
}

void GMMain::DrawFrame(engine* Engine) {
    auto LBackground = Engine->CreateLayer();
    Engine->SetDrawTarget(LBackground);

    m_resourcesManager.drawFrame(Engine);
    m_timeManager.drawFrame(Engine);
    m_screenManager.drawFrame(Engine);
    m_tasksManager.drawFrame(Engine);
    m_loggerManager.drawFrame(Engine);
    m_menuManager.drawFrame(Engine);
    
    Engine->EnableLayer(LBackground, true);
    Engine->SetDrawTarget(nullptr);
}

void GMMain::Draw(engine* Engine) {
    Engine->Clear(olc::BLANK);
    m_resourcesManager.draw(Engine);
    m_timeManager.draw(Engine);
    m_screenManager.draw(Engine);
    m_tasksManager.draw(Engine);
    m_loggerManager.draw(Engine);
    m_menuManager.draw(Engine);
}

GMMain::~GMMain() {

}

void GMMain::submit() {
    m_menuManager.submit();
}

void GMMain::quit() {
    m_menuManager.quit();
}

void GMMain::up() {
    m_menuManager.prev();
}

void GMMain::down() {
    m_menuManager.next();
}

void GMMain::left() {
}

void GMMain::right() {
}