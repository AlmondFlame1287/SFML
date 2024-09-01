#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


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

        // -- FUNCS -- //
        void initVars();
        void initWindow();
};