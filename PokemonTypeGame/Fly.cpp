#include "Fly.hpp"

bool Fly::move(std::vector<Npc> *enemies)
{
	for (size_t i{ 0 };i < enemies->size(); i++) {
		if (sprite->getGlobalBounds().findIntersection((enemies->at(i).sprite->getGlobalBounds())))
			enemies->erase(enemies->begin() + i);
			return false;
	}
	return true;
}
