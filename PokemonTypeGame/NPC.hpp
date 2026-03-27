#pragma once
#include "print.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
class Npc
{
public:
	bool alive = true;
    sf::Texture texture;
    sf::Sprite *sprite;

    Npc() {
        if (!texture.loadFromFile("Sprites/NPC/NPC.png", false, sf::IntRect({ 0,0 }, { 16,16 })))
        {
            std::cout << "Failed to load textures " << "!\n";
        }
        print("Texturen geladen!\n");
        sprite = new sf::Sprite(texture);
        sprite->setScale(sf::Vector2f(5.f, 5.f));
        print("NPC erstellt!\n");
    }
    void destroy() {
        delete sprite;
        print("NPC zerstört!\n");
	}
};