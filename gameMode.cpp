#include "gameMode.hpp"

const int gameMode::borderThickness = 3;

gameMode::gameMode(const int maxWidth, const int maxHeight) :
m_maxWidth(maxWidth),
m_maxHeight(maxHeight),
m_inProgress(true),
m_newMode(nullptr)
{
}

bool gameMode::inProgress() const {
    return m_inProgress;
}

gameMode::~gameMode() {
}

bool gameMode::modeChanged() const {
    return m_newMode? true : false;
}

gameMode* gameMode::getNewMode() const {
    return m_newMode;
}