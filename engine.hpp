#pragma once
#include "olcPixelGameEngine.h"

enum class eColor {
    primary,
    secondary,
    background,
    highlight,
    border,
    font,
    font_selected,
    font_disabled,
    font_disabled_selected
};

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
    engine();
    void begin();
    void setGameMode(class gameMode* newGameMode);
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    ~engine();

    static olc::Pixel getColor(eColor color);
};

