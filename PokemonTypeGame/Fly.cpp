#include "Fly.hpp"

bool Fly::isShooting;

void Fly::fly()
{
	sprite->move(move_vector);
}

bool Fly::move(std::vector<Npc> *enemies)
{
	for (size_t i{ 0 };i < enemies->size(); i++) {
		if (sprite->getGlobalBounds().findIntersection((enemies->at(i).sprite->getGlobalBounds()))) {
			enemies->at(i).alive = false;
			enemies->at(i).sprite->setPosition(sf::Vector2f( - 100.f, -100.f));
			alive = false;
			sprite->setPosition(sf::Vector2f(-100.f, -100.f));
			return false;
		}
	}
	return true;
}
