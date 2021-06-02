#pragma once
#include <stack>
#include "UIManager.hpp"
#include "menu.hpp"
#include "observer.hpp"
#include "eSignals.hpp"

class menuManager : public UIManager {
    menu m_menu;
    int m_currentIndex;
    std::stack<menu*> m_menuStack;
    observer<menu> m_observer;
    
public:
    menuManager(const long beginX, const long beginY, const long endX, const long endY, eColors bgColor);
    
    void setMenu(menu&& menu);
    void draw(class engine* engine) override;

    void submit();
    void quit();
    void next();
    void prev();
  
    void checkCurrent(eSignals signal);
    const menu& connect(const menu& menu, eSignals signal, std::function<void(class menu&)> slot);
};
