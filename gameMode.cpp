#include "gameMode.hpp"
#include "menuManager.hpp"

gameMode::gameMode(const int maxWidth, const int maxHeight) :
m_maxWidth(maxWidth),
m_maxHeight(maxHeight),
m_inProgress(true),
m_menuManager(nullptr)
{
    m_menuManager = new menuManager();
}

bool gameMode::inProgress() const {
    return m_inProgress;
}

gameMode::~gameMode() {
    delete m_menuManager;
}
