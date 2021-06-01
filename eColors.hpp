#pragma once

#include "engine.hpp"

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

static olc::Pixel getColor(eColor color) {
    switch (color) {
    case eColor::primary:
        return olc::Pixel(32, 34, 37);
    case eColor::secondary:
        return olc::Pixel(54, 57, 63);
    case eColor::background:
        return olc::Pixel(47, 49, 54);
    case eColor::highlight:
        return olc::Pixel(57, 60, 67);
    case eColor::border:
        return olc::Pixel(66, 69, 74);
    case eColor::font:
        return olc::Pixel(115, 126, 140);
    case eColor::font_selected:
        return olc::Pixel(255, 255, 255);
    case eColor::font_disabled:
        return olc::Pixel(75, 75, 75);
    case eColor::font_disabled_selected:
        return olc::Pixel(125, 125, 125);
    }
}