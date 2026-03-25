#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Background.hpp"
#include "Input.hpp"
#include <iostream>

class Game
{
private:
    sf::RenderWindow window;
    sf::Vector2f center;
    sf::View camera;
    Player player;
    Background background;
    sf::Texture t;
    float frame;
public:
    Game(){
		frame = 0;
    }
    int run();
};