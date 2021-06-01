#include "menuManager.hpp"
#include "engine.hpp"
#include <iostream>

menuManager::menuManager(const long beginX, const long beginY, const long endX, const long endY, eColor color) :
UIManager(beginX, beginY, endX, endY, color),
m_currentIndex(0)
{
    m_padding = 16;
}

void menuManager::setMenu(menu&& menu) {
    m_menu = std::move(menu);
    m_menuStack.push(&m_menu);
    m_menuStack.top()->option(m_currentIndex).setSelected(true);
}

void menuManager::draw(engine* engine) {
    olc::Pixel color;
    auto menu = *m_menuStack.top();
    for (int i = 0; i < menu.getItemsCount(); i++) {
        if (menu.option(i).isSelected() && menu.option(i).isDisabled()) color = getColor(eColor::font_disabled_selected);
        else if (menu.option(i).isSelected()) color = getColor(eColor::font_selected);
        else if (menu.option(i).isDisabled()) color = getColor(eColor::font_disabled);
        else color = getColor(eColor::font);
        engine->DrawString(m_stepsX / 2 - menu.option(i).getNameLength(), m_stepsY / 2 + i * m_padding, menu.option(i).getName(), color);
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
