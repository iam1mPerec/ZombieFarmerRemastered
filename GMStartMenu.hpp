#pragma once

#include "gameMode.hpp"
#include "menuManager.hpp"
#include "olcPixelGameEngine.h"

class GMStartMenu : public gameMode {
    menuManager m_menuManager;
public:
    GMStartMenu(const int maxWidth, const int maxHeight);
    void DrawFrame(class engine* engine) override;
    void Draw(class engine* engine) override;
    
    //MARK: - slots
    void onLoadPressed(class menu& sender);
    void onLoadSlotPressed(class menu& sender, int slot);
    void onLoadSlotChecked(class menu& receiver, int slot);
    void onStartPressed(class menu& sender);
    void onQuitPressed(class menu& sender);
    
    //MARK: - User input
    void submit() override;
    void quit() override;
    void up() override;
    void down() override;
    
    ~GMStartMenu();
};
