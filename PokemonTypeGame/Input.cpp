#include "Input.hpp"
#include "Fly.hpp"
#include <vector>

void input(Player* p, float SPEED, sf::RenderWindow* window, sf::View* camera, const float frames, const sf::Sprite* background, std::vector<Fly> *flies) {
    sf::Vector2f localposition = ((p->sprite->getPosition() - camera->getCenter()) + sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
    if (camera->getCenter().x < background->getTextureRect().size.x - window->getSize().x / 2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && localposition.x > window->getSize().x * 0.8) {
            camera->move(sf::Vector2f(SPEED, 0));
        }
    }
    if (camera->getCenter().y < background->getTextureRect().size.y - window->getSize().y / 2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && localposition.y > window->getSize().y * 0.8) {
            camera->move(sf::Vector2f(0, SPEED));
        }
    }
    if (camera->getCenter().x > window->getSize().x / 2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && localposition.x < window->getSize().x * 0.2) {
            camera->move(sf::Vector2f(-SPEED, 0));
        }
    }
    if (camera->getCenter().y > window->getSize().y / 2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && localposition.y < window->getSize().y * 0.2) {
            camera->move(sf::Vector2f(0, -SPEED));
        }
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        p->setUp();
        if (p->sprite->getPosition().y > 0) {
            p->animate(frames);
            p->sprite->move(sf::Vector2f(0, -SPEED));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        p->setLeft();
        if (p->sprite->getPosition().x > 0) {
            p->animate(frames);
            p->sprite->move(sf::Vector2f(-SPEED, 0));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        p->setDown();
        if (p->sprite->getPosition().y < background->getTextureRect().size.y - p->sprite->getTextureRect().size.y * p->sprite->getScale().y) {
            p->animate(frames);
            p->sprite->move(sf::Vector2f(0, SPEED));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        p->setRight();
        if (p->sprite->getPosition().x < background->getTextureRect().size.x - p->sprite->getTextureRect().size.x * p->sprite->getScale().x) {
            p->animate(frames);
            p->sprite->move(sf::Vector2f(SPEED, 0));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		std::cout << "Shoot!\n";
        p->shoot(flies);
    }
    window->setView(*camera);
}
