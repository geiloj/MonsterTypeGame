#include "Game.hpp"

int Game::run()
{
    print("Launching Game...\n");
    window = sf::RenderWindow(sf::VideoMode({ WINDOW_WIDTH/2, WINDOW_HEIGHT/2 }), "FROG!");
    camera = window.getDefaultView();
    center = sf::Vector2f(unsigned int(window.getSize().x / 2), unsigned int(window.getSize().y / 2)+100);
	
    window.setFramerateLimit(FRAMERATE_LIMIT);
    camera.setCenter(center);

    player.sprite->setPosition(center);

    for (size_t i{0}; i < enemies.size(); i++) {
        enemies.at(i).sprite->setPosition(center + sf::Vector2f(200.f * (i/10+1), 90*(i%10+1)));
    }

    while (window.isOpen())
    {
        print(player.direction);
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
		for (size_t i{0}; i < player.flies.size(); i++) {

			if (player.flies.at(i).move(&enemies) && !player.flies.at(i).fly()) {
			}
			else {
				player.flies.erase(player.flies.begin() + i);
				continue;
			}
			if (player.flies.at(i).alive)
				window.draw(*(player.flies.at(i).sprite));
		}
        int count = 0;
		window.draw(*(player.sprite));

        sf::Rect rect(camera.getCenter() - sf::Vector2f(window.getSize().x/2, window.getSize().y/2), camera.getCenter() + sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
		for (Npc enemie : enemies) {
            if (rect.contains(enemie.sprite->getPosition()) && enemie.alive) {
                count++;
                window.draw(*(enemie.sprite));
            }
        }
        std::cout << rect.getCenter().x << " " << rect.getCenter().y << " " << camera.getCenter().x << " " << camera.getCenter().y << std::endl;
        window.display();
    }
	return -1;
}
