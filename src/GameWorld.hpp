/**
 * @file GameWorld.hpp
 * @brief GameWorld classe de declaração.
 * @version 0.1
 * @date 25/02/2024
 * @copyright copyright (c) 2024 Silvanei Martins
 *
 * @author Silvanei Martins
 */

#pragma once

#include <raylib.h>

#include "Map.h"
#include "Mario.h"
#include "Drawable.hpp"
#include "GameState.hpp"

class GameWorld : public virtual Drawable {
    public:
        static bool debug;
        static bool showFPS;
        static bool immortalMario;
        static GameState state;
        static float gravity;

        /**
         * @brief Construa um novo objeto GameWorld.
        */
        GameWorld();

        /**
         * @brief Destrói o objeto GameWorld.
        */
        ~GameWorld() override;

        /**
         * @brief Lê a entrada do usuário e atualiza o estado do jogo.
        */
        void inputAndUpdate();

        /**
         * @brief Desenha o estado atual do jogo.
        */
        void draw() override;

        /**
         * @brief Carregue recursos do jogo como imagens, texturas, sons, fontes, shaders, etc.
         * Deve ser chamado dentro do construtor.
        */
        static void loadResources();

        /**
         * @brief Descarregue recursos do jogo como imagens, texturas, sons, fontes, shaders, etc.
         * Deve ser chamado dentro do destrutor.
        */
        static void unloadResources();

        void setCamera( Camera2D *camera );

        void resetMap();
        void resetGame();
        void nextMap();
        void pauseGame( bool playPauseSFX, bool pauseMusic, bool showOverlay );

        bool isPauseMusicOnPause() const;
        bool isShowOverlayOnPause() const;

    private:
        Mario mario;
        Map map;
        Camera2D *camera;
        bool showControls;
        GameState stateBeforePause;
        int remainingTimePointCount;

        bool pauseMusic;
        bool showOverlayOnPause;

        bool irisOutFinished;
        float irisOutTime;
        float irisOutAcum;
};
