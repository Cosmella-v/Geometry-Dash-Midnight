#include "Game Objects Factory/main.hpp"
#include "Game Objects Factory/impl.hpp"
#include <Geode/Geode.hpp>
using namespace geode::prelude;
#include "namespace.hpp"

void registerCustomObjects();
#define Portal(sprite, backsprite, more) GameObjectsFactory::createObjectConfig(UNIQ_ID("test"))->refID(1933)->SetHasBeenActivatedBypass(true)->tab(5)->SetActivatedByPlayerBypass(true)->insertIndex((12 * 2) + 3)->customSetup( \
            [](GameObject* obj) { \
                log::debug("{}({})", __func__, obj); \
                obj->initWithSpriteFrameName(sprite); \
            } \
        )->activatedByPlayer( \
            [] (EnhancedGameObject* obj, PlayerObject* player) { \
                more; \
                player->playSpawnEffect(); \
            } \
        )->HasbeenActivatedByPlayer( [](PlayerObject* player) {  })->registerMe();

$execute{ registerCustomObjects(); }
inline void registerCustomObjects() {
    Portal("portal_11_front_001.png","portal_11_front_001.png",
           log::debug("crashed?"); if (player->m_isRobot) {return;}; player->toggleRobotMode(true,true))
}