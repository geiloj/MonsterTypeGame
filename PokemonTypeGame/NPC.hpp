#pragma once
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
        std::cout << "Texturen geladen!\n";
        sprite = new sf::Sprite(texture);
        sprite->setScale(sf::Vector2f(5.f, 5.f));
        std::cout << "NPC erstellt!\n";
    }
    void destroy() {
        delete sprite;
        std::cout << "NPC zerstört!\n";
	}
};