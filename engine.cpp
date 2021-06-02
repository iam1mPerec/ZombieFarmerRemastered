#include "engine.hpp"
#include "GMStartMenu.hpp"

const int engine::charHeight = 7;
const int engine::charWidth = 4;

void engine::drawBorder(int x, int y, int w, int h, enum eColors color, int thickness) {
    for (int i = 0; i < thickness; i++) {
        DrawRect(x + i, y + i, w - 2 * i, h - 2 * i, getColor(color));
    }
}

void engine::clearLayers() {
    GetLayers().resize(1);
}

engine::engine() :
m_mode(nullptr)
{
    sAppName = "Zombie Farm 2.0";
}
void engine::begin() {
    if (Construct(900, 600, 1, 1)) {
        m_mode = new GMStartMenu(ScreenWidth(), ScreenHeight());
        Start();
    }
}

void engine::setGameMode(gameMode* newGameMode) {
    if(m_mode) {
        delete m_mode;
    }
    m_mode = newGameMode;
    clearLayers();
    m_mode->DrawFrame(this);
}

bool engine::OnUserCreate() {
    m_mode->DrawFrame(this);
    return true;
}

bool engine::OnUserUpdate(float fElapsedTime) {
    //MARK: - Handle input
    if (GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::F).bPressed) m_mode->submit();
    if (GetKey(olc::Key::BACK).bPressed || GetKey(olc::Key::ESCAPE).bPressed || GetKey(olc::Key::E).bPressed) m_mode->quit();
    if (GetKey(olc::Key::UP).bPressed || GetKey(olc::Key::W).bPressed) m_mode->up();
    if (GetKey(olc::Key::DOWN).bPressed || GetKey(olc::Key::S).bPressed) m_mode->down();
    if (GetKey(olc::Key::LEFT).bPressed || GetKey(olc::Key::A).bPressed) m_mode->left();
    if (GetKey(olc::Key::RIGHT).bPressed || GetKey(olc::Key::D).bPressed) m_mode->right();
    //MARK: - Update state
    if (m_mode->modeChanged()) {
        setGameMode(m_mode->getNewMode());
    }
    //MARK: - Render
    m_mode->Draw(this);
    
    return m_mode->inProgress();
}

engine::~engine() {
    delete m_mode;
}