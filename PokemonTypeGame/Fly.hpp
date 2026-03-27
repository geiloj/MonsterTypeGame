#pragma once
#include "Npc.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
class Fly
{
private:
	const float SPEED = 6.f;
public:
    sf::Texture texture;
    sf::Sprite* sprite;
	sf::Vector2f move_vector;
	static bool isShooting;
	bool alive = true;
	Fly() {
	}

    Fly(char direction, sf::Vector2f pos) {
		if (!texture.loadFromFile("Sprites/FLY/Fly.png", false, sf::IntRect({ 0,0 }, { 2,1 })))
        {
            std::cout << "Failed to load textures\n";
        }
        sprite = new sf::Sprite(texture);
		sprite->setScale(sf::Vector2f(10.f, 10.f));
		
		switch (direction)
		{
			case 'r':
				move_vector = sf::Vector2f(SPEED, 0.f);
				break;
			case 'l':
				move_vector = sf::Vector2f(-SPEED, 0.f);
				break;
			case 'u':
				move_vector = sf::Vector2f(0.f, -SPEED);
				break;
			case 'd':
				move_vector = sf::Vector2f(0.f, SPEED);
				break;
		}
			sprite->setPosition(pos);
    }
	void fly();
    bool move(std::vector<Npc> *enemies);
};