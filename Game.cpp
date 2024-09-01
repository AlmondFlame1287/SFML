#include "Game.h"

// -- CONSTR, DESTR -- //

Game::Game() {
    this->initVars();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

// -- PUBLIC FUNCS -- //

void Game::update() {
    this->pollEvts();
}

void Game::pollEvts() {
    while(this->window->pollEvent(this->evt)) {
        switch (this->evt.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->evt.key.code == sf::Keyboard::Escape)
                    this->window->close();

            default:
                break;
        }
    }
}

void Game::render() {
    this->window->clear();

    // Draw stuff in here

    this->window->display();
}

// -- ACCESSORS -- // 

const bool Game::isWindowOpen() const {
    return this->window->isOpen();
}

// -- PRIVATE FUNCS -- //

void Game::initVars() {
    // We dynamically allocate a window so we can destroy it
    // when needed
    this->window = nullptr;
    this->videoMode.height = 600;
    this->videoMode.width = 800;
}

void Game::initWindow() {
    // sf::Style::Titlebar = gives the window a title bar 
    // sf::Style::Close = gives the window a close button
    
    this->window = new sf::RenderWindow(this->videoMode, "Test", sf::Style::Titlebar | sf::Style::Close);
}