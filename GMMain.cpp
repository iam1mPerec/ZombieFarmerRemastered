#include "GMMain.hpp"
#include "engine.hpp"
#include "eColors.hpp"
#include "plant.hpp"
#include "building.hpp"
#include "goods.hpp"
#include <iostream>

GMMain::GMMain(const int maxWidth, const int maxHeight) :
    gameMode(maxWidth, maxHeight),
    m_resourcesManager(0, 0, maxWidth - maxWidth/5, 25, eColors::primary),
    m_timeManager(maxWidth - maxWidth/5, 0, maxWidth, 25, eColors::primary),
    m_screenManager(0, 25, maxWidth - maxWidth/5, maxHeight - maxHeight / 4, eColors::font_disabled_selected),
    m_tasksManager(maxWidth - maxWidth/5, 25, maxWidth, maxHeight - maxHeight / 4, eColors::secondary),
    m_loggerManager(0, maxHeight - maxHeight/4, maxWidth - maxWidth/5, maxHeight, eColors::secondary),
    m_menuManager(maxWidth - maxWidth/5, maxHeight - maxHeight/4, maxWidth, maxHeight, eColors::background)
{
    menu MENU;
    
    m_menuManager.connect(MENU["Planting"], eSignals::click, [&](menu& sender) { this->onPlantingClicked(sender); });

    m_menuManager.connect(MENU["Planting"]["Potatos"], eSignals::click, [&](menu& sender) { this->onPlanting(sender, plant()); });
    m_menuManager.connect(MENU["Planting"]["Corn"], eSignals::click, [&](menu& sender) { this->onPlanting(sender, plant()); });
    m_menuManager.connect(MENU["Planting"]["Tomatos"], eSignals::click, [&](menu& sender) { this->onPlanting(sender, plant()); });
    m_menuManager.connect(MENU["Planting"]["Carrots"], eSignals::click, [&](menu& sender) { this->onPlanting(sender, plant()); });
    m_menuManager.connect(MENU["Planting"]["Pumpkins"], eSignals::click, [&](menu& sender) { this->onPlanting(sender, plant()); });
    m_menuManager.connect(MENU["Planting"]["Cherry"], eSignals::click, [&](menu& sender) { this->onPlanting(sender, plant()); });

    m_menuManager.connect(MENU["Building"], eSignals::click, [&](menu& sender) { this->onBuildingClicked(sender); });

    m_menuManager.connect(MENU["Building"]["Fence"], eSignals::click, [&](menu& sender) { this->onBuilding(sender, building()); });
    m_menuManager.connect(MENU["Building"]["Tunel"], eSignals::click, [&](menu& sender) { this->onBuilding(sender, building()); });
    m_menuManager.connect(MENU["Building"]["House"], eSignals::click, [&](menu& sender) { this->onBuilding(sender, building()); });
    m_menuManager.connect(MENU["Building"]["Tent"], eSignals::click, [&](menu& sender) { this->onBuilding(sender, building()); });
    m_menuManager.connect(MENU["Building"]["Barracks"], eSignals::click, [&](menu& sender) { this->onBuilding(sender, building()); });

    m_menuManager.connect(MENU["Activities"], eSignals::click, [&](menu& sender) { this->onActivitiesClicked(sender); });

    m_menuManager.connect(MENU["Activities"]["Chop"], eSignals::click, [&](menu& sender) { this->onChopClicked(sender); });
    m_menuManager.connect(MENU["Activities"]["Scavange"], eSignals::click, [&](menu& sender) { this->onScavangeClicked(sender); });
    m_menuManager.connect(MENU["Activities"]["Collect"], eSignals::click, [&](menu& sender) { this->onCollectClicked(sender); });
    m_menuManager.connect(MENU["Activities"]["Shop"], eSignals::click, [&](menu& sender) { this->onShopClicked(sender); });

    m_menuManager.connect(MENU["Activities"]["Shop"]["Buy"], eSignals::click, [&](menu& sender) { this->onBuyClicked(sender); });

    m_menuManager.connect(MENU["Activities"]["Shop"]["Buy"]["Wood"], eSignals::click, [&](menu& sender) { this->onBuying(sender, goods()); });
    m_menuManager.connect(MENU["Activities"]["Shop"]["Buy"]["Seeds"], eSignals::click, [&](menu& sender) { this->onBuying(sender, goods()); });
    m_menuManager.connect(MENU["Activities"]["Shop"]["Buy"]["Food"], eSignals::click, [&](menu& sender) { this->onBuying(sender, goods()); });

    m_menuManager.connect(MENU["Activities"]["Shop"]["Sell"], eSignals::click, [&](menu& sender) { this->onSellClicked(sender); });

    m_menuManager.connect(MENU["Activities"]["Shop"]["Sell"]["Wood"], eSignals::click, [&](menu& sender) { this->onSelling(sender, goods()); });
    m_menuManager.connect(MENU["Activities"]["Shop"]["Sell"]["Seeds"], eSignals::click, [&](menu& sender) { this->onSelling(sender, goods()); });
    m_menuManager.connect(MENU["Activities"]["Shop"]["Sell"]["Food"], eSignals::click, [&](menu& sender) { this->onSelling(sender, goods()); });

    m_menuManager.connect(MENU["Activities"]["Shop"]["Hire Farmers"], eSignals::click, [&](menu& sender) { this->onHireFarmersClicked(sender); });

    m_menuManager.connect(MENU["Roster"], eSignals::click, [&](menu& sender) { this->onRosterClicked(sender); });

    m_menuManager.connect(MENU["Roster"]["Skills"], eSignals::click, [&](menu& sender) { this->onSkillsClicked(sender); });
    m_menuManager.connect(MENU["Roster"]["Items"], eSignals::click, [&](menu& sender) { this->onItemsClicked(sender); });
    m_menuManager.connect(MENU["Roster"]["Feed"], eSignals::click, [&](menu& sender) { this->onFeedClicked(sender); });
    
    m_menuManager.connect(MENU["Save"], eSignals::click, [&](menu& sender) { this->onSaveClicked(sender); });

    m_menuManager.connect(MENU["Save"]["slot 1"], eSignals::click, [&](menu& sender) { this->onSaveSlotClicked(sender, 1); });
    m_menuManager.connect(MENU["Save"]["slot 2"], eSignals::click, [&](menu& sender) { this->onSaveSlotClicked(sender, 2); });
    m_menuManager.connect(MENU["Save"]["slot 3"], eSignals::click, [&](menu& sender) { this->onSaveSlotClicked(sender, 3); });
        
    m_menuManager.connect(MENU["Exit"], eSignals::click, [&](menu& sender) { this->onExitClicked(sender); });

    m_menuManager.connect(MENU["Exit"]["Yes"], eSignals::click, [&](menu& sender) { this->onExit(sender, true); });
    m_menuManager.connect(MENU["Exit"]["No"], eSignals::click, [&](menu& sender) { this->onExit(sender, false); });

    m_menuManager.setMenu(std::move(MENU));
}

void GMMain::print(std::string msg) {
    m_loggerManager.print(m_timeManager.getTimeStamp(), msg);
}

void GMMain::DrawFrame(engine* Engine) {
    auto LBackground = Engine->CreateLayer();
    Engine->SetDrawTarget(LBackground);

    m_resourcesManager.drawFrame(Engine);
    m_timeManager.drawFrame(Engine);
    m_screenManager.drawFrame(Engine);
    m_tasksManager.drawFrame(Engine);
    m_loggerManager.drawFrame(Engine);
    m_menuManager.drawFrame(Engine);
    
    Engine->EnableLayer(LBackground, true);
    Engine->SetDrawTarget(nullptr);
}

void GMMain::Draw(engine* Engine) {
    Engine->Clear(olc::BLANK);
    m_resourcesManager.draw(Engine);
    m_timeManager.draw(Engine);
    m_screenManager.draw(Engine);
    m_tasksManager.draw(Engine);
    m_loggerManager.draw(Engine);
    m_menuManager.draw(Engine);
}

GMMain::~GMMain() {

}

void GMMain::submit() {
    m_menuManager.submit();
    m_screenManager.submit();
}

void GMMain::quit() {
    m_menuManager.quit();
    m_screenManager.quit();
}

void GMMain::up() {
    m_menuManager.up();
    m_screenManager.up();
}

void GMMain::down() {
    m_menuManager.down();
    m_screenManager.down();
}

void GMMain::left() {
    m_screenManager.left();
}

void GMMain::right() {
    m_screenManager.right();
}

//MARK: - Slots

void GMMain::onPlantingClicked(menu& sender) {
    m_screenManager.setMode(eScreenModes::inventory);
}

void GMMain::onPlanting(menu& sender, const plant& plant) {

}

void GMMain::onBuildingClicked(menu& sender) {

}

void GMMain::onBuilding(menu& sender, const building& building) {

}

void GMMain::onActivitiesClicked(menu& sender) {

}

void GMMain::onChopClicked(menu& sender) {

}

void GMMain::onScavangeClicked(menu& sender) {

}

void GMMain::onCollectClicked(menu& sender) {

}

void GMMain::onShopClicked(menu& sender) {

}

void GMMain::onBuyClicked(menu& sender) {

}

void GMMain::onBuying(class menu& sender, const goods& goods) {

}

void GMMain::onSellClicked(menu& sender) {

}

void GMMain::onSelling(menu& sender, const goods& goods) {

}

void GMMain::onHireFarmersClicked(menu& sender) {

}

void GMMain::onRosterClicked(menu& sender) {
    m_screenManager.setMode(eScreenModes::roster);
}

void GMMain::onSkillsClicked(menu& sender) {

}

void GMMain::onItemsClicked(menu& sender) {

}

void GMMain::onFeedClicked(menu& sender) {

}

void GMMain::onSaveClicked(menu& sender) {

}

void GMMain::onSaveSlotClicked(menu& sender, int slot) {

}

void GMMain::onExitClicked(menu& sender) {

}

void GMMain::onExit(menu& sender, bool confirm) {
    if (confirm) m_inProgress = false;  
    else quit();
}
