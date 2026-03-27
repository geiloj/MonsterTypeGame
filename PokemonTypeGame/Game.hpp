#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Background.hpp"
#include "Input.hpp"
#include "NPC.hpp"
#include "Fly.hpp"
#include <iostream>

class Game
{
private:
    std::vector<Npc> *enemies = new std::vector<Npc>(5);
    std::vector<Fly> *flies = new std::vector<Fly>(5);
    sf::RenderWindow window;
    sf::View camera;
    sf::Vector2f center;
    Player player;
    Background background;
    sf::Texture t;
    float frame;
public:
    Game(){
		frame = 0;
    }
    ~Game() {
        delete enemies;
        delete flies;
	}
    int run();
};