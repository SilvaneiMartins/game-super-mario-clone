/**
 * @file Map.hpp
 * @brief Map classe de declaração.
 * @version 0.1
 * @date 25/02/2024
 * @copyright copyright (c) 2024 Silvanei Martins
 *
 * @author Silvanei Martins
*/
#pragma once

class Block;
class GameWorld;

#include <vector>
#include <raylib.h>

#include "Baddie.hpp"
#include "Block.hpp"
#include "Item.hpp"
#include "Mario.hpp"
#include "Tile.hpp"
#include "Drawable.hpp"

class Map : public virtual Drawable
{
    public:
        static constexpr int TILE_WIDTH = 32;
        static constexpr Color DEBUGGABLE_TILE_COLOR = Color(0, 0, 0, 0);

        Map(Mario &mario, int id, bool loadTestMap, bool parseBlocks, bool parseItems, bool parseBaddies, GameWorld* gw);
        ~Map() override;
        void draw() override;

        void parseMap();

        void setMarioOffset(float marioOffset);
        void setDrawBlackScreen(bool drawBlackScreen);
        void setDrawMessage(bool drawMessage);
        void setMessage(std::string message);
        void setCamera(Camera2D *camera);
        void setGameWorld(GameWorld *gw);

        std::vector<Tile*> &getTiles();
        std::vector<Block*>& getBlocks();
        std::vector<Item*> &getItems();
        std::vector<Item*> &getStaticItems();
        std::vector<Baddie*> &getBaddies();

        float getMaxWidth() const;
        float getMaxHeight() const;

        void playMusic() const;
        void reset();
        bool next();
        void first();
        void pauseGameToShowMessage() cons
    private:
        std::vector<Tile *> tiles;
        std::vector<Tile *> backScenarioTiles;
        std::vector<Tile *> frontScenarioTiles;
        std::vector<Block *> blocks;
        std::vector<Block *> messageBlocks;
        std::vector<Item *> items;
        std::vector<Item *> staticItems;
        std::vector<Baddie *> baddies;

        int id;
        int maxId;

        float maxWidth;
        float maxHeight;

        Mario& mario;
        float marioOffset;

        int backgroundId;
        int maxBackgroundId;
        Color backgroundColor;
        Texture2D backgroundTexture;
        bool drawBackScreen;
        float drawBlackScreenFadeAcum;
        float drawBlackScreenFadeTime;

        int musicId;
        int maxMusicId;

        bool parseBlocks;
        bool parseItems;
        bool parseBaddies;

        bool loadTestMap;
        bool parsed;

        bool drawMessage;
        std::string message;
        Camera2D *camera;
        GameWorld *gw;
};
