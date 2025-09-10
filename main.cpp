#include <SFML/Graphics.hpp>

#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(683, 384), "Platypus");
    window.setFramerateLimit(60);

    Game game(&window);

    while (window.isOpen()) {
        game.Start();
    }

    return 0;
}