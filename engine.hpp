#pragma once
#include "olcPixelGameEngine.h"
#include "eColors.hpp"

struct EnumClassHash
{
    template <typename T>
    std::size_t operator[](T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

class engine : public olc::PixelGameEngine {
    //implementing gameMod ref as a part of the Strategy desighn patern
    //gameMode will tell the engine what to draw where and when
    //the engine would handle drawing and keyboard events
    class gameMode* m_mode;
public:
    //MARK: - My additions to olcPixelGameEngine
    void drawBorder(int x, int y, int w, int h, olc::Pixel pixel, int thickness);
    void clearLayers();

    //MARK: - other staff
    engine();
    void begin();
    void setGameMode(class gameMode* newGameMode);
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    ~engine();
};

