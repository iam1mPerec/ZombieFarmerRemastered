#pragma once
#include "olcPixelGameEngine.h"
#include "eColors.hpp"

class engine : public olc::PixelGameEngine {
    //implementing gameMod ref as a part of the Strategy desighn patern
    //gameMode will tell the engine what to draw where and when
    //the engine would handle drawing and keyboard events
    class gameMode* m_mode;
public:
    static const int charHeight;
    static const int charWidth;
    //MARK: - My additions to olcPixelGameEngine
    void drawBorder(int x, int y, int w, int h, enum class eColors color, int thickness);
    void clearLayers();

    //MARK: - other staff
    engine();
    void begin();
    void setGameMode(class gameMode* newGameMode);
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    ~engine();
};
