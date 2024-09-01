#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main() {

    // sf::Style::Titlebar = gives the window a title bar 
    // sf::Style::Close = gives the window a close button
    
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Test", sf::Style::Titlebar | sf::Style::Close);
    sf::Event evt;

    while(window.isOpen()) {

        // the window listens to events
        while(window.pollEvent(evt)) {
            switch (evt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(evt.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    break;
            }
        }
    }

    // Update loop
    // ---- Empty for now ---- //


    // Render stuff
    window.clear();

    // Draw your stuff here

    window.display(); // Draw call
    

    return 0;
}