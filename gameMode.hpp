#pragma once

class gameMode {
protected:
    const int m_maxWidth, m_maxHeight;
    bool m_inProgress;
    gameMode* m_newMode;
    
    static const int borderThickness;
public:
    gameMode(const int maxWidth, const int maxHeight);
    virtual void DrawFrame(class engine* engine) = 0;
    virtual void Draw(class engine* engine) = 0;
    bool inProgress() const;
    bool modeChanged() const;
    gameMode* getNewMode() const;
    
    virtual void submit() {};
    virtual void quit() {};
    virtual void up() {};
    virtual void down() {};
    virtual void left() {};
    virtual void right() {};
    
    virtual ~gameMode();
};
