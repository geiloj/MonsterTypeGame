#include "Game.hpp"

int Game::run()
{
    std::cout << "Launching Game...\n";
    window = sf::RenderWindow(sf::VideoMode({ 800, 600 }), "FROG!");
    center = sf::Vector2f(unsigned int(window.getSize().x / 2), unsigned int(window.getSize().y / 2));
    camera = window.getDefaultView();



    for (size_t i{ 0 }; i < enemies->size(); i++) {
        enemies->at(i).sprite->setPosition(center + sf::Vector2f(200.f*i, 90.f));
    }
    frame = 0;
    window.setFramerateLimit(60);
    camera.setCenter(center);
    player.sprite->setPosition(center);
	
    while (window.isOpen())
    {
		std::cout << flies->size() << " flies on screen!\n";
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
        frame += 1.8;
        input(&player, 5.f, &window, &camera, frame, background.background, flies);
        window.clear();
        window.draw(*(background.background));
        for (int i{ 0 }; i < flies->size(); i++) {
			flies->at(i).move(enemies);
            window.draw(*(flies->at(i).sprite));
		}
        window.draw(*(player.sprite));
        for (size_t i{ 0 }; i < enemies->size(); i++) {
            window.draw(*(enemies->at(i).sprite));
        }

        window.display();
    }
}
