/**
 * GameWorld.cpp
 * @brief GameWorld classe de implementação.
 * @version 0.1
 * @date 25/02/2024
 * @copyright copyright (c) 2024 Silvanei Martins
 *
 * @author Silvanei Martins
 */
#include <string>
#include <vector>
#include <iostream>

#include "Baddie.h"
#include "Block.h"
#include "GameState.h"
#include "GameWorld.h"
#include "Item.h"
#include "Mario.h"
#include "raylib.hpp"
#include "Tile.hpp"
#include "utils.hpp"
#include "GameWorld.hpp"
#include "SpriteState.hpp"
#include "ResourceManager.hpp"


#define RAYGUI_IMPLEMENTATION
#undef RAYGUI_IMPLEMENTATION

// #define Release

#ifdef RELEASE
#define ACTIVATE_DEBUG false
#define ALLOW_ENABLE_CONTROLS false
#define INITIAL_MAP_ID 1
#define LOAD_TEST_MAP false
#define PARSE_BLOCKS true
#define PARSE_ITEMS true
#define PARSE_BADDIES true
GameState GameWorld::state = GAME_STATE_TITLE_SCREEN;
#else
#define ACTIVATE_DEBUG true
#define ALLOW_ENABLE_CONTROLS true
#define INITIAL_MAP_ID 1
#define LOAD_TEST_MAP false
#define PARSE_BLOCKS true
#define PARSE_ITEMS true
#define PARSE_BADDIES true
GameState GameWorld::state = GAME_STATE_PLAYING;
#endif

bool GameWorld::debug = ACTIVATE_DEBUG;
bool GameWorld::showFPS = ACTIVATE_DEBUG;
bool GameWorld::immortalMario = ACTIVATE_DEBUG;
float GameWorld::gravity = 20;

GameWorld::GameWorld()
{

}
