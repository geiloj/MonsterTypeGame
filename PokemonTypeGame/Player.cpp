#include "Player.hpp"

void Player::animate(const float frames)
{
	int offset = 0;
	switch (direction)
	{
	case 'r':
		offset = 8;
		break;
	case 'l':
		offset = 6;
		break;
	case 'u':
		offset = 4;
		break;
	case 'd':
		offset = 2;
		break;
	}
	if (frames < 15) {
		sprite->setTexture(textures->at((int)(offset / 2.f) - 1));
		return;
	}
	if (frames < 30) {
		sprite->setTexture(textures->at(2 + offset));
		return;
	}
	if (frames < 45) {
		sprite->setTexture(textures->at((int)(offset/2.f)-1));
		return;
	}
	if (frames < 60) {
		sprite->setTexture(textures->at(3 + offset));
		return;
	}
}

void Player::eat(const float frames)
{
	int offset = 1;
	if (frames < 15) {
		sprite->setTexture(textures->at(3));
		return;
	}
	if (frames < 30) {
		sprite->setTexture(textures->at(12));
		return;
	}
	if (frames < 45) {
		sprite->setTexture(textures->at(3));
		return;
	}
	if (frames < 60) {
		sprite->setTexture(textures->at(13));
		return;
	}
}

void Player::setLeft()
{
	direction = 'l';
	updateSprite();
}

void Player::setRight()
{
	direction = 'r';
	updateSprite();
}

void Player::setUp()
{
	direction = 'u';
	updateSprite();
}

void Player::setDown()
{
	direction = 'd';
	updateSprite();
}

void Player::updateSprite()
{
	switch (direction)
	{
		case 'l':
			sprite->setTexture(textures->at(2));
			break;
		case 'r':
			sprite->setTexture(textures->at(3));
			break;
		case 'u':
			sprite->setTexture(textures->at(1));
			break;
		case 'd':
			sprite->setTexture(textures->at(0));
			break;
	}
}

void Player::shoot()
{
	flies->push_back(Fly(direction,sf::Vector2f((sprite->getPosition().x + (sprite->getTextureRect().size.x*sprite->getScale().x/2)),(sprite->getPosition().y + (sprite->getTextureRect().size.y * sprite->getScale().y / 2)))));
}
