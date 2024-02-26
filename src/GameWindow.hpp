/**
 * @file GameWindow.hpp
 * @brief GameWindow classe de declaração. Esta classe contém uma instância de
 * o Game World e é responsável por criar uma nova janela do Raylib,
 * inicie o loop do jogo e finalize a janela do Raylib.
 * @version 0.1
 * @date 25/02/2024
 * @copyright copyright (c) 2024 Silvanei Martins
 *
 * @author Silvanei Martins
 */
#pragma once

#include <string>
#include <raylib.h>

#include "GameWorld.hpp"

class GameWindow
{
    public:
        /**
         * @brief Construct a new Game Window object
         */
        GameWindow();
        GameWindow( bool initAudio );
        GameWindow( int width, int height, std::string title, bool initAudio );
        GameWindow( int width, int height, std::string title, int targetFPS, bool initAudio );
        GameWindow( int width, int height, std::string title, bool antialiasing, bool initAudio );
        GameWindow( int width, int height, std::string title, int targetFPS, bool antialiasing, bool initAudio );
        GameWindow( int width, int height, std::string title, int targetFPS,
                    bool antialiasing, bool resizable, bool fullScreen,
                    bool undecorated, bool alwaysOnTop, bool alwaysRun, bool initAudio );

        /**
         * @brief Construa um novo objeto Game Window
         */
        ~GameWindow();

        /**
         * @brief Inicializa a Janela, inicia o loop do jogo e, quando
         * termina, a janela também estará finalizada.
         */
        void init();

        // getters
        int getWidth() const;
        int getHeight() const;
        std::string getTitle() const;
        int getTargetFPS() const;
        bool isAntialiasing() const;
        bool isResizable() const;
        bool isFullScreen() const;
        bool isUndecorated() const;
        bool isAlwaysOnTop() const;
        bool isAlwaysRun() const;
        bool isInitAudio() const;
        bool isInitialized() const;

        // setters
        void setWidth( int width );
        void setHeight( int height );
        void setTitle( std::string title );
        void setTargetFPS( int targetFPS );
        void setAntialiasing( bool antialiasing );
        void setResizable( bool resizable );
        void setFullScreen( bool fullScreen );
        void setUndecorated( bool undecorated );
        void setAlwaysOnTop( bool alwaysOnTop );
        void setAlwaysRun( bool alwaysRun );
        void setInitAudio( bool initAudio );

    private:
        int width;
        int height;
        std::string title;

        int targetFPS;
        bool antialiasing;
        bool resizable;
        bool fullScreen;
        bool undecorated;
        bool alwaysOnTop;
        bool alwaysRun;
        bool initAudio;

        GameWorld gw;
        Camera2D camera;

        bool initialized;
};
