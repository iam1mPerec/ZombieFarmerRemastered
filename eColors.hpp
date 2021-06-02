#pragma once

#include "engine.hpp"

enum class eColors {
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

static olc::Pixel getColor(eColors color) {
    switch (color) {
    case eColors::primary:
        return olc::Pixel(32, 34, 37);
    case eColors::secondary:
        return olc::Pixel(54, 57, 63);
    case eColors::background:
        return olc::Pixel(47, 49, 54);
    case eColors::highlight:
        return olc::Pixel(57, 60, 67);
    case eColors::border:
        return olc::Pixel(66, 69, 74);
    case eColors::font:
        return olc::Pixel(115, 126, 140);
    case eColors::font_selected:
        return olc::Pixel(255, 255, 255);
    case eColors::font_disabled:
        return olc::Pixel(75, 75, 75);
    case eColors::font_disabled_selected:
        return olc::Pixel(125, 125, 125);
    }
}