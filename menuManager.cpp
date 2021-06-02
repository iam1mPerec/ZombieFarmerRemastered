#include "menuManager.hpp"
#include "engine.hpp"
#include <iostream>

menuManager::menuManager(const long beginX, const long beginY, const long endX, const long endY, eColors color) :
UIManager(beginX, beginY, endX, endY, color),
m_currentIndex(0)
{
    m_padding = 8;
}

void menuManager::setMenu(menu&& menu) {
    m_menu = std::move(menu);
    m_menuStack.push(&m_menu);
    m_menuStack.top()->option(m_currentIndex).setSelected(true);
}

void menuManager::draw(engine* Engine) {
    if (m_menuStack.empty()) return;
    olc::Pixel color;
    auto menu = m_menuStack.top();
    for (int i = 0; i < menu->getItemsCount(); i++) {
        if (menu->option(i).isSelected() && menu->option(i).isDisabled()) color = getColor(eColors::font_disabled_selected);
        else if (menu->option(i).isSelected()) color = getColor(eColors::font_selected);
        else if (menu->option(i).isDisabled()) color = getColor(eColors::font_disabled);
        else color = getColor(eColors::font);

        int height = menu->getItemsCount() * (m_padding + engine::charHeight) - m_padding;
        Engine->DrawString(m_beginX + m_stepsX/2 - menu->option(i).getNameLength() * engine::charWidth, 
            m_beginY + (m_stepsY - height)/ 2 + i*(m_padding + engine::charHeight), menu->option(i).getName(), color);
    }
}

//MARK: - controller
void menuManager::submit() {
    m_observer.dispatch(m_menuStack.top()->option(m_currentIndex), eSignals::click);
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

void menuManager::checkCurrent(eSignals signal) {
    for (auto &option : m_menuStack.top()->option(m_currentIndex)) {
        m_observer.dispatch(option, signal);
    }
}

const menu& menuManager::connect(const menu& menu, eSignals signal, std::function<void(class menu&)> slot) {
    m_observer.connect(menu.getID(), signal, slot);
    return menu;
}
