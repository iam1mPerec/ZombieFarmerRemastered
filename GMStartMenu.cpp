#include "GMStartMenu.hpp"
#include "menuManager.hpp"
#include "menu.hpp"
#include "engine.hpp"

GMStartMenu::GMStartMenu(const int maxWidth, const int maxHeight) :
gameMode(maxWidth, maxHeight)
{
    //MARK: - StartMenu observers
    menu menu;
    m_menuManager->connect(&menu["start"], [&](){ this->onStartPressed(); });
    m_menuManager->connect(&menu["load"],  [&](){ this->onLoadPressed(); });
    m_menuManager->connect(&menu["load"]["slot 1"], [&](){ this->onLoadSlotPressed(1); });
    m_menuManager->connect(&menu["load"]["slot 2"], [&](){ this->onLoadSlotPressed(2); });
    m_menuManager->connect(&menu["load"]["slot 3"], [&](){ this->onLoadSlotPressed(3); });
    m_menuManager->connect(&menu["quit"], [&](){ this->onQuitPressed(); });
    
    m_menuManager->setMenuDimensions(0, 0, m_maxWidth, m_maxHeight);
    m_menuManager->setMenu(std::move(menu));
}

//MARK: - slots definition
void GMStartMenu::onStartPressed() {
    std::cout<<"start was just pressed!"<<std::endl;
}
void GMStartMenu::onLoadPressed() {
    std::cout << "load was just pressed!" << std::endl;
}
void GMStartMenu::onLoadSlotPressed(int slot) {
    std::cout << "load slot #"<< slot << " was just pressed!" << std::endl;
}
void GMStartMenu::onQuitPressed() {
    std::cout << "quit was just pressed!" << std::endl;
    m_inProgress = false;
}

void GMStartMenu::Draw(engine* Engine) {
    Engine->Clear(engine::getColor(eColor::primary));
    Engine->DrawRect(1, 1, Engine->ScreenWidth()-2, Engine->ScreenHeight()-2, engine::getColor(eColor::border));
    m_menuManager->draw(Engine);
}

void GMStartMenu::submit() {
    m_menuManager->submit();
}

void GMStartMenu::quit() {
    m_menuManager->quit();
}

void GMStartMenu::up() {
    m_menuManager->prev();
}

void GMStartMenu::down() {
    m_menuManager->next();
}

void GMStartMenu::left() {

}

void GMStartMenu::right() {

}

GMStartMenu::~GMStartMenu() {
}
