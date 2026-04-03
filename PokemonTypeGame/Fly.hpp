#pragma once
#include "Npc.hpp"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
class Fly
{
private:
	const float SPEED = 16.f;
	float accelerate = 1.f;
	static sf::Texture texture;
public:
	std::unique_ptr<sf::Sprite> sprite;
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
		sprite = std::make_unique<sf::Sprite>(texture);
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
			case 'q':
				move_vector = sf::Vector2f(-SPEED, -SPEED);
				break;
			case 'e':
				move_vector = sf::Vector2f(SPEED, -SPEED);
				break;
			case 'y':
				move_vector = sf::Vector2f(-SPEED, SPEED);
				break;
			case 'c':
				move_vector = sf::Vector2f(SPEED, SPEED);
				break;
		}
			sprite->setPosition(pos);
    }
	bool fly();
    bool move(std::vector<Npc> *enemies);

	Fly(const Fly&) = delete;
	Fly& operator=(const Fly&) = delete;

	Fly(Fly&& other) noexcept
		: sprite(std::move(other.sprite)),
		  move_vector(other.move_vector),
		  accelerate(other.accelerate),
		  alive(other.alive)
	{}

	Fly& operator=(Fly&& other) noexcept
	{
		if (this != &other) {
			sprite = std::move(other.sprite);
			move_vector = other.move_vector;
			accelerate = other.accelerate;
			alive = other.alive;
		}
		return *this;
	}
};