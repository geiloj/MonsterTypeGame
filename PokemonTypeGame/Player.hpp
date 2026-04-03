#pragma once
#include <format>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Fly.hpp"
#include "print.hpp"
class Player
{
public:
    std::vector<sf::Texture> textures;
    std::unique_ptr<sf::Sprite> sprite;
	char direction = 'd';
	int animationDelay = 0;
	std::vector<Fly> flies;

    Player() : textures(14) {
        for (int i = 0; i < 14;i++) {
            if (!textures.at(i).loadFromFile(std::format("Sprites/FROG/FROG{}.png", i + 1), false, sf::IntRect({0,0}, {16,16})))
            {
                std::cout << "Failed to load textures " << i <<"!\n";
            }
        }
        print("Texturen geladen!\n");
        sprite = std::make_unique<sf::Sprite>(textures.at(0));
        sprite->setScale(sf::Vector2f(5.f, 5.f));
        print("Player erstellt!\n");
    }
 

    void animate(const float frames);
    void eat(const float frames);
    void setLeft();
    void setRight();
    void setUp();
    void setDown();
    void setTopLeft();
    void setTopRight();
    void setBottomLeft();
    void setBottomRight();
    void updateSprite();
	void shoot();
};