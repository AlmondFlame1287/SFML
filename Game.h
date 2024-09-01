#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// TODO: To remove
#include <iostream>

class Game {
    public:
        // -- CONSTR, DESTR -- // 
        Game();
        virtual ~Game();
        
        // -- FUNCS -- //
        void update();
        void pollEvts();
        void render();

        // -- ACCESSORS -- //
        const bool isWindowOpen() const;

    private:
        // -- VARS -- //
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event evt;

        // -- GAME OBJS -- //
        // KEEP NOTE: RectShape is not something we
        // should be using if we intend to add textures
        sf::RectangleShape enemy;

        // -- FUNCS -- //
        void initVars();
        void initWindow();
        void initEnemies();
};