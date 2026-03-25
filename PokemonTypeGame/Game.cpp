#include "Game.hpp"

int Game::run()
{
    std::cout << "Launching Game...\n";
    window = sf::RenderWindow(sf::VideoMode({ 800, 600 }), "FROG!");
    center = sf::Vector2f(window.getSize().x / 2, (window.getSize().y / 2));
    camera = window.getDefaultView();
	
    frame = 0;
    window.setFramerateLimit(60);
    camera.setCenter(center);
    player.sprite->setScale(sf::Vector2f(5.f, 5.f));
    player.sprite->setPosition(center);
	
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()){
                window.close();
                return 0;
        }
        }
        if (frame >= 60) {
            frame = 0;
        }
        frame++;
        input(&player, 5.f, &window, &camera, frame, background.background);
        window.clear();
        window.draw(*(background.background));
        window.draw(*(player.sprite));
        window.display();
    }
}
