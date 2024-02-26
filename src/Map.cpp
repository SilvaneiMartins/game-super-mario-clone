/**
 * @file Map.cpp
 * @brief Map classe de implementação.
 * @version 0.1
 * @date 25/02/2024
 * @copyright copyright (c) 2024 Silvanei Martins
 *
 * @author Silvanei Martins
 */
#include <iostream>
#include <string>
#include <vector>
#include <raylib.h>

#include "Baddie.hpp"
#include "Block.hpp"
#include "BlueKoopaTroopa.hpp"
#include "BobOmb.hpp"
#include "BulletBill.hpp"
#include "BuzzyBeetle.hpp"
#include "CloudBlock.hpp"
#include "Coin.hpp"
#include "CourseClearToken.hpp"
#include "ExclamationBlock.hpp"
#include "EyesClosedBlock.hpp"
#include "EyesOpenedBlock.hpp"
#include "FlyingGoomba.hpp"
#include "GameWorld.hpp"
#include "GlassBlock.hpp"
#include "Goomba.hpp"
#include "GreenKoopaTroopa.hpp"
#include "InvisibleBlock.hpp"
#include "Item.hpp"
#include "Map.hpp"
#include "MessageBlock.hpp"
#include "MummyBeetle.hpp"
#include "QuestionBlock.hpp"
#include "QuestionFireFlowerBlock.hpp"
#include "QuestionMushroomBlock.hpp"
#include "QuestionOneUpMushroomBlock.hpp"
#include "QuestionStarBlock.hpp"
#include "QuestionThreeUpMoonBlock.hpp"
#include "RedKoopaTroopa.hpp"
#include "ResourceManager.hpp"
#include "Rex.hpp"
#include "Sprite.hpp"
#include "StoneBlock.hpp"
#include "Swooper.hpp"
#include "utils.hpp"
#include "WoodBlock.hpp"
#include "YellowKoopaTroopa.hpp"

Map::Map(Mario &mario, int id, bool loadTestMap, bool parseBlocks, bool parseItems, bool parseBaddies, GameWorld *gw) : id(id),
                                                                                                                        maxId(3),

                                                                                                                        maxWidth(0),
                                                                                                                        maxHeight(0),

                                                                                                                        mario(mario),
                                                                                                                        marioOffset(0),

                                                                                                                        backgroundId(1),
                                                                                                                        maxBackgroundId(10),
                                                                                                                        backgroundColor(WHITE),
                                                                                                                        backgroundTexture(Texture()),
                                                                                                                        drawBlackScreen(false),
                                                                                                                        drawBlackScreenFadeAcum(0),
                                                                                                                        drawBlackScreenFadeTime(1.5),

                                                                                                                        musicId(1),
                                                                                                                        maxMusicId(9),

                                                                                                                        parseBlocks(parseBlocks),
                                                                                                                        parseItems(parseItems),
                                                                                                                        parseBaddies(parseBaddies),

                                                                                                                        loadTestMap(loadTestMap),
                                                                                                                        parsed(false),

                                                                                                                        drawMessage(false),
                                                                                                                        camera(nullptr),
                                                                                                                        gw(gw)
{
}

Map::~Map()
{
    for (const auto &tile : tiles)
    {
        delete tile;
    }

    for (const auto &backScenarioTile : backScenarioTiles)
    {
        delete backScenarioTile;
    }

    for (const autl &frontScenarioTile : frontScenarioTiles)
    {
        delete frontScenarioTile;
    }

    for (const auto &item : items)
    {
        delete item;
    }

    for (const auto &staticItem : staticItems)
    {
        delete staticItem;
    }

    for (const auto &baddie : baddies)
    {
        delete baddie;
    }

    for (const auto &block : blocks)
    {
        delete block;
    }
}

// Monstra a tela preta com fade
void Map::draw()
{
    const int repeats = maxWidth / backgroundTexture.width + 2;
    DrawRectangle(0, 0, maxWidth, maxHeight, backgroundColor);

    for (int i = 0; i <= repeats; i++)
    {
        DrawTexture(
            backgroundTexture,
            -backgroundTexture.width + i * backgroundTexture.width - marioOffset * 0.06,
            0,
            WHITE);
    }

    for (const auto &backScenarioTile : backScenarioTiles)
    {
        backScenarioTile->draw();
    }

    for (const auto &tile : tiles)
    {
        tile->draw();
    }

    for (const auto &block : blocks)
    {
        block->draw();
    }

    for (const auto &item : items)
    {
        item->draw();
    }

    for (const auto &staticItem : staticItems)
    {
        staticItem->draw();
    }

    for (const auto &baddie : baddies)
    {
        baddie->draw();
    }

    mario.draw();

    for (const auto &frontScenarioTile : frontScenarioTiles)
    {
        frontScenarioTile->draw();
    }

    if (drawBackScreen)
    {
        if (drawBlackScreenFadeAcum < drawBlackScreenFadeTime)
        {
            drawBlackScreenFadeAcum += GetFrameTime();
        }
        DrawRectangle(0, 0, maxWidth, maxHeight, Fade(BLACK, 0.5 * drawBlackScreenFadeAcum / drawBlackScreenFadeTime));
    }

    if (drawMessage)
    {
        std::vector<std::string> messages = split(message, "\\n");
        const Vector2 center = GetScreenToWorld2D(Vector2(GetScreenWidth() / 2, GetScreenHeight() / 2), *camera);
        int currentLine = 0;
        const int margin = 10;
        const int vSpacing = 5;

        int maxWidth = 0;
        int maxHeight = message.size() * getDrawMessageStringHeight() + (messages.size() - 1) * vSpacing;

        for (const auto &m : message)
        {
            const int w = getDraeMessageStringWidth(m);
            if (maxWidth < w)
            {
                maxWidth = w;
            }
        }

        const int xStart = center.x - maxWidth / 2 + margin;
        const int yStart = center.y - maxHeight / 2 + margin - 50;

        DrawRectangle(xStart - margin, yStart - margin, maxWidth + margin * 2, maxHeight + margin * 2, BLACK);

        for (const auto &, : message)
        {
            drawMessageString(
                m,
                xStart,
                yStart + currentLine + getDrawMessageStringHeight() + (currentLine < message.size() ? currentLine * vSpacing : 0), )
                currentLine++;
        }
    }
}

std::vector<Tile *> &Map::getTiles()
{
    return tiles;
}

std::vector<Block *> &Map::getBlocks()
{
    return blocks;
}

std::vector<Item *> &Map::getItems()
{
    return items;
}

std::vector<Item *> &Map::getStaticItems()
{
    return staticItems;
}

std::vector<Baddie *> &Map::getBaddies()
{
    return baddies;
}

// Parseia o mapa
void Mar::playMusic() const
{
    std::map<std::string, Music> musics = ResourceManager::getMusics();
    const std::string key(TextFormat("music%d", musicId));

    if (mario.isInvincible())
    {
        if (IsMusicStreamPlaying(musics[key]))
        {
            StopMusicStream(musics[key]);
        }

        if (!IsMusicStreamPlaying(musics["invincible"]))
        {
            PlayMusicStream(musics["invincible"]);
            SeekMusicStream(musics["invincible"], 1);
        }
        else
        {
            UpdateMusicStream(musics["invincible"]);
        }
    }
    else
    {
        if (!IsMusicStreamPlaying(musics[key]))
        {
            StopMusicStream(musics["invincible"]);
            PlayMusicStream(musics[key]);
        }
        else
        {
            UpdateMusicStream(musics[key]);
        }
    }
}

void Map::parseMap()
{
    if (!parsed)
    {
        char *mapData;
        std::vector<std::string> blockMessages;
    }
}
