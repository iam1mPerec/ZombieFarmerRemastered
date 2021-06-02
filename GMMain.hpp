#pragma once
#include "gameMode.hpp"
#include "resourcesManager.hpp"
#include "timeManager.hpp"
#include "screenManager.hpp"
#include "tasksManager.hpp"
#include "loggerManager.hpp"
#include "menuManager.hpp"

class GMMain : public gameMode
{
    resourcesManager m_resourcesManager;
    timeManager m_timeManager;
    screenManager m_screenManager;
    tasksManager m_tasksManager;
    loggerManager m_loggerManager;
    menuManager m_menuManager;

public:
    GMMain(const int maxWidth, const int maxHeight);
    void Draw(class engine* engine) override;
    void DrawFrame(class engine* engine) override;

    //MARK: - slots

    //MARK: - User input
    void submit() override;
    void quit() override;
    void up() override;
    void down() override;
    void left() override;
    void right() override;

    ~GMMain();
};

