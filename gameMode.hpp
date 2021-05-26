#pragma once

class gameMode {
protected:
    const int m_maxWidth, m_maxHeight;
    bool m_inProgress;
    class menuManager* m_menuManager;
public:
    gameMode(const int maxWidth, const int maxHeight);
    virtual void Draw(class engine* engine) = 0;
    bool inProgress() const;
    
    virtual void submit() {};
    virtual void quit() {};
    virtual void up() {};
    virtual void down() {};
    virtual void left() {};
    virtual void right() {};
    
    virtual ~gameMode();
};
