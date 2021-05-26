#pragma once
#include "menu.hpp"
#include "menuObserver.hpp"
#include <stack>

class menuManager {

    static const long padding = 16;
    
    menu m_menu;
    int m_currentIndex;
    std::stack<menu*> m_menuStack;
    menuObserver m_observer;
    long m_beginX, m_endX, m_beginY, m_endY;
    
public:
    menuManager();
    
    void setMenu(menu&& menu);
    void setMenuDimensions(const long beginX, const long beginY, const long endX, const long endY);
    
    void draw(class engine* engine);
    
    void submit();
    void quit();
    void next();
    void prev();
  
    void dispatch(int signal);
    menu* connect(menu* menu, std::function<void()> slot);
};
