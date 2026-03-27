#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "print.hpp"

#define BACKGROUND_WIDTH 800
#define BACKGROUND_HEIGHT 600
#define MAP_SIZE 100

class Background
{
private:
	sf::Texture texture;
public:
	sf::Sprite* background;
	Background() {
		print("Loading Background textures...\n");
        if (!texture.loadFromFile("Sprites/Background/BACKGROUND.png", false, sf::IntRect({0,0}, {800,600})))
        {
            std::cout << "Failed to load Background textures!\n";
        }
		texture.setRepeated(true);
		background = new sf::Sprite(texture);
		background->setTextureRect(sf::IntRect({ 0,0 }, {BACKGROUND_WIDTH*MAP_SIZE,BACKGROUND_HEIGHT*MAP_SIZE}));
		print("Background textures loaded!\n");
    }
};

