#pragma once
#include <format>
#include <iostream>
#include <SFML/Graphics.hpp>
class Player
{
public:
	sf::Texture textures[14];
    sf::Sprite* sprite;
    int animationDelay = 0;

    Player() {
        for (int i = 0; i < 14;i++) {
            if (!textures[i].loadFromFile(std::format("Sprites/FROG/FROG{}.png", i + 1), false, sf::IntRect({0,0}, {32,16})))
            {
                std::cout << "Failed to load textures " << i <<"!\n";
            }
        }
        std::cout << "Texturen geladen!\n";
        sprite = new sf::Sprite(textures[0]);
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
private:
	char direction = 'd';
};