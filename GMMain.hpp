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
    void print(std::string msg);
    void Draw(class engine* engine) override;
    void DrawFrame(class engine* engine) override;

    //MARK: - User input
    void submit() override;
    void quit() override;
    void up() override;
    void down() override;
    void left() override;
    void right() override;

    //MARK: - Slots
    void onPlantingClicked(class menu& sender);
    void onPlanting(class menu& sender, const class plant& plant);
    void onBuildingClicked(class menu& sender);
    void onBuilding(class menu& sender, const class building& building);
    void onActivitiesClicked(class menu& sender);
    void onChopClicked(class menu& sender);
    void onScavangeClicked(class menu& sender);
    void onCollectClicked(class menu& sender);
    void onShopClicked(class menu& sender);
    void onBuyClicked(class menu& sender);
    void onBuying(class menu& sender, const class goods& goods);
    void onSellClicked(class menu& sender);
    void onSelling(class menu& sender, const class goods& goods);
    void onHireFarmersClicked(class menu& sender);
    void onRosterClicked(class menu& sender);
    void onSkillsClicked(class menu& sender);
    void onItemsClicked(class menu& sender);
    void onFeedClicked(class menu& sender);
    void onSaveClicked(class menu& sender);
    void onSaveSlotClicked(class menu& sender, int slot);
    void onExitClicked(class menu& sender);
    void onExit(class menu& sender, bool confirm);
    ~GMMain();
};

