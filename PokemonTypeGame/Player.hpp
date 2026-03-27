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
    std::vector<sf::Texture>* textures = new std::vector<sf::Texture>(14);
    sf::Sprite* sprite;
	char direction = 'd';
    int animationDelay = 0;
	std::vector<Fly> *flies = new std::vector<Fly>(0);

    Player() {
		isShooting = false;
        for (int i = 0; i < 14;i++) {
            if (!textures->at(i).loadFromFile(std::format("Sprites/FROG/FROG{}.png", i + 1), false, sf::IntRect({0,0}, {16,16})))
            {
                std::cout << "Failed to load textures " << i <<"!\n";
            }
        }
        std::cout << "Texturen geladen!\n";
        sprite = new sf::Sprite(textures->at(0));
        sprite->setScale(sf::Vector2f(5.f, 5.f));
        std::cout << "Player erstellt!\n";
    }
 
    ~Player() {
        delete sprite;
		delete flies;
    }

    void animate(const float frames);
    void eat(const float frames);
    void setLeft();
    void setRight();
    void setUp();
    void setDown();
    void updateSprite();
	void shoot();
};