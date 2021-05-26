#include "menuManager.hpp"
#include "engine.hpp"
#include <iostream>

menuManager::menuManager() :
m_beginX(0),
m_beginY(0),
m_endX(0),
m_endY(0),
m_currentIndex(0)
{
    
}

void menuManager::setMenu(menu&& menu) {
    std::cout << "start option address after moving: " << &menu["start"] << std::endl;
    m_menu = std::move(menu);
    m_menuStack.push(&m_menu);
    m_menuStack.top()->option(m_currentIndex).setSelected(true);
}

void menuManager::setMenuDimensions(const long beginX, const long beginY, const long endX, const long endY) {
    m_beginX = beginX;
    m_beginY = beginY;
    m_endX = endX;
    m_endY = endY;
}

void menuManager::draw(engine* engine) {
    olc::Pixel color;
    auto menu = *m_menuStack.top();
    for (int i = 0; i < menu.getItemsCount(); i++) {
        if (menu.option(i).isSelected() && menu.option(i).isDisabled()) color = engine::getColor(eColor::font_disabled_selected);
        else if (menu.option(i).isSelected()) color = engine::getColor(eColor::font_selected);
        else if (menu.option(i).isDisabled()) color = engine::getColor(eColor::font_disabled);
        else color = engine::getColor(eColor::font);
        engine->DrawString((m_endX - m_beginX) / 2 - menu.option(i).getNameLength(), (m_endY - m_beginY) / 2 + i * padding, menu.option(i).getName(), color);
    }
}

//MARK: - controller
void menuManager::submit() {
    m_observer.dispatch(m_menuStack.top()->option(m_currentIndex).signal());
    if (!m_menuStack.top()->option(m_currentIndex).getItemsCount()) return;
    m_menuStack.push(&m_menuStack.top()->option(m_currentIndex));
    m_currentIndex = 0;
    m_menuStack.top()->option(m_currentIndex).setSelected(true);
}

void menuManager::quit() {
    if (m_menuStack.size() <= 1) return;
    m_menuStack.top()->option(m_currentIndex).setSelected(false);
    m_menuStack.pop();
    m_currentIndex = m_menuStack.top()->getSelected();
}

void menuManager::next() {
    if(m_menuStack.top()->getItemsCount()) {
        m_menuStack.top()->option(m_currentIndex).setSelected(false);

        if (++m_currentIndex == m_menuStack.top()->getItemsCount()) m_currentIndex = 0;
        
        m_menuStack.top()->option(m_currentIndex).setSelected(true);
    }
}

void menuManager::prev() {
    if(m_menuStack.top()->getItemsCount()) {
        m_menuStack.top()->option(m_currentIndex).setSelected(false);

        if (--m_currentIndex < 0) m_currentIndex = m_menuStack.top()->getItemsCount() - 1;
        
        m_menuStack.top()->option(m_currentIndex).setSelected(true);
    }
}

//MARK: - signal handling staff

void menuManager::dispatch(int signal) {
    m_observer.dispatch(signal);
}

menu* menuManager::connect(menu* menu, std::function<void()> slot) {
    m_observer.connect(menu->signal(), slot);
    return menu;
}
