#pragma once
#include <stack>
#include "UIElement.hpp"
#include "menu.hpp"
#include "observer.hpp"
#include "eSignals.hpp"

class menuManager : public UIElement {
    menu m_menu;
    int m_currentIndex;
    std::stack<menu*> m_menuStack;
    observer<menu> m_observer;
    
public:
    menuManager(const long beginX, const long beginY, const long endX, const long endY, eColors bgColor);
    
    void setMenu(menu&& menu);
    void draw(class engine* engine) override;

    void quit() override;
    void submit() override;
    void down() override;
    void up() override;
  
    void checkCurrent(eSignals signal);
    const menu& connect(const menu& menu, eSignals signal, std::function<void(class menu&)> slot);
};
