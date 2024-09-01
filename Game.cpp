#include "Game.h"

// -- CONSTR, DESTR -- //

Game::Game() {
    this->initVars();
    this->initWindow();
    this->initEnemies();
}

Game::~Game() {
    delete this->window;
}

// -- PUBLIC FUNCS -- //

void Game::update() {
    this->pollEvts();

    // Get mouse position RELATIVE TO THE SCREEN
    // std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << sf::Mouse::getPosition().y << "\n";

    // Get mouse position RELATIVE TO THE WINDOW
    std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << "," << sf::Mouse::getPosition(*this->window).y << "\n";
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
    
    // ATTENTION: Do NOT draw stuff on the window directly
    // as it might be dangerous (This time is fine because I'm experimenting) 
    this->window->draw(this->enemy);

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
    this->window->setFramerateLimit(60);
}

void Game::initEnemies() {
    this->enemy.setPosition(30.f, 50.f);
    this->enemy.setSize(sf::Vector2f(50.f, 50.f));
    this->enemy.setFillColor(sf::Color::Red);
    this->enemy.setOutlineColor(sf::Color::White);
    this->enemy.setOutlineThickness(1.f);
}