#include "Game.hpp"

int Game::run()
{
    std::cout << "Launching Game...\n";
    window = sf::RenderWindow(sf::VideoMode({ 1600, 1200 }), "FROG!");
    camera = window.getDefaultView();

    center = sf::Vector2f(unsigned int(window.getSize().x / 2), unsigned int(window.getSize().y / 2));
    window.setFramerateLimit(60);
    camera.setCenter(center);
    player.sprite->setPosition(center);

    for (size_t i{ 0 }; i < enemies->size(); i++) {
        enemies->at(i).sprite->setPosition(center + sf::Vector2f(200.f * (i/10+1), 90*(i%10+1)));
    }

    while (window.isOpen())
    {
        if (frame >= 60) {
            frame = 0;
        }
        frame += 1.8;
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()){
                window.close();
                return 0;
            }
        }
        /*INPUT*/
        input(&player, 5.f, &window, &camera, frame, background.background);
        /*DRAWING*/
        window.clear();
        window.draw(*(background.background));
        for (size_t i{ 0 }; i < player.flies->size(); i++) {
            if (player.flies->at(i).move(enemies)) {
                player.flies->at(i).fly();
            }
            window.draw(*(player.flies->at(i).sprite));
        }
        window.draw(*(player.sprite));
        for (size_t i{ 0 }; i < enemies->size(); i++) {
            if(enemies->at(i).alive)
                window.draw(*(enemies->at(i).sprite));
        }
        window.display();
    }
	return -1;
}
