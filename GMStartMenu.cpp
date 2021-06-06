#include "GMStartMenu.hpp"
#include "GMMain.hpp"
#include "menuManager.hpp"
#include "menu.hpp"
#include "engine.hpp"
#include "eSignals.hpp"

GMStartMenu::GMStartMenu(const int maxWidth, const int maxHeight) :
gameMode(maxWidth, maxHeight),
m_menuManager(0, 0, maxWidth, maxHeight, eColors::primary)
{
    //MARK: - StartMenu observers
    menu MENU;
    m_menuManager.connect(MENU["start"], eSignals::click, [&](menu& sender){ this->onStartPressed(sender); });
    m_menuManager.connect(MENU["load"], eSignals::click, [&](menu& sender){ this->onLoadPressed(sender); });
    auto slot_1 = m_menuManager.connect(MENU["load"]["slot 1"], eSignals::click, [&](menu& sender) { this->onLoadSlotPressed(sender, 1); });
    auto slot_2 = m_menuManager.connect(MENU["load"]["slot 2"], eSignals::click, [&](menu& sender) { this->onLoadSlotPressed(sender, 2); });
    auto slot_3 = m_menuManager.connect(MENU["load"]["slot 3"], eSignals::click, [&](menu& sender) { this->onLoadSlotPressed(sender, 3); });
    m_menuManager.connect(slot_1, eSignals::check, [&](menu& receiver) { this->onLoadSlotChecked(receiver, 1); });
    m_menuManager.connect(slot_2, eSignals::check, [&](menu& receiver) { this->onLoadSlotChecked(receiver, 2); });
    m_menuManager.connect(slot_3, eSignals::check, [&](menu& receiver) { this->onLoadSlotChecked(receiver, 3); });
    m_menuManager.connect(MENU["quit"], eSignals::click, [&](menu& sender) { this->onQuitPressed(sender); });
    
    m_menuManager.setMenu(std::move(MENU));
}

//MARK: - slots definition
void GMStartMenu::onStartPressed(menu& sender) {
    m_newMode = new GMMain(m_maxWidth, m_maxHeight);
}
void GMStartMenu::onLoadPressed(menu& sender) {
    m_menuManager.checkCurrent(eSignals::check);
}
void GMStartMenu::onLoadSlotPressed(menu& sender, int slot) {

}
void GMStartMenu::onLoadSlotChecked(menu& receiver, int slot) {
    receiver.setDissabled(true);
}
void GMStartMenu::onQuitPressed(menu& sender) {
    m_inProgress = false;
}

void GMStartMenu::DrawFrame(engine* Engine) {
    auto bgLayer = Engine->CreateLayer();
    Engine->SetDrawTarget(bgLayer);
    m_menuManager.drawFrame(Engine);
    Engine->EnableLayer(bgLayer, true);
    Engine->SetDrawTarget(nullptr);
}

void GMStartMenu::Draw(engine* Engine) {
    Engine->Clear(olc::BLANK);
    m_menuManager.draw(Engine);
}

void GMStartMenu::submit() {
    m_menuManager.submit();
}

void GMStartMenu::quit() {
    m_menuManager.quit();
}

void GMStartMenu::up() {
    m_menuManager.up();
}

void GMStartMenu::down() {
    m_menuManager.down();
}

GMStartMenu::~GMStartMenu() {
}
