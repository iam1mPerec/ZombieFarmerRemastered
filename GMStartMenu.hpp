#pragma once

#include "gameMode.hpp"
#include "olcPixelGameEngine.h"

class GMStartMenu : public gameMode {
public:
    GMStartMenu(const int maxWidth, const int maxHeight);
    void Draw(class engine* engine) override;
    
    //MARK: - slots
    void onLoadPressed();
    void onLoadSlotPressed(int slot);
    void onStartPressed();
    void onQuitPressed();
    
    //MARK: - User input
    void submit() override;
    void quit() override;
    void up() override;
    void down() override;
    void left() override;
    void right() override;
    
    ~GMStartMenu();
};
