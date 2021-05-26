#include "engine.hpp"
#include "GMStartMenu.hpp"

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
}

bool engine::OnUserCreate() {
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
    
    //MARK: - Render
    m_mode->Draw(this);
    
    return m_mode->inProgress();
}

engine::~engine() {
    delete m_mode;
}

//MARK: - Palette
olc::Pixel engine::getColor(eColor color) {
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