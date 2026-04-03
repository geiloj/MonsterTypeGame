#include "Fly.hpp"

sf::Texture Fly::texture;
bool Fly::isShooting;

bool Fly::fly()
{
	if (accelerate < 0) {
		return true;
	}
	accelerate -= 0.013f;
	sprite->move(sf::Vector2f(move_vector.x*accelerate, move_vector.y*accelerate));
	return false;
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
