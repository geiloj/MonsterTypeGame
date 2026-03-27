#pragma once
#include <format>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fly.hpp"
class Player
{
private:
	bool isShooting;
public:
	sf::Texture textures[14];
    sf::Sprite* sprite;
	char direction = 'd';
    int animationDelay = 0;

    Player() {
		isShooting = false;
        for (int i = 0; i < 14;i++) {
            if (!textures[i].loadFromFile(std::format("Sprites/FROG/FROG{}.png", i + 1), false, sf::IntRect({0,0}, {32,16})))
            {
                std::cout << "Failed to load textures " << i <<"!\n";
            }
        }
        std::cout << "Texturen geladen!\n";
        sprite = new sf::Sprite(textures[0]);
        sprite->setScale(sf::Vector2f(5.f, 5.f));
        std::cout << "Player erstellt!\n";
    }
 
    ~Player() {
        delete sprite;
    }

    void animate(const float frames);
    void eat(const float frames);
    void setLeft();
    void setRight();
    void setUp();
    void setDown();
    void updateSprite();
	void shoot(std::vector<Fly> *flies);
};