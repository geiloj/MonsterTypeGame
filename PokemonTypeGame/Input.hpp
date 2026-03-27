#include "Player.hpp"
#include "Fly.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

void input(Player* p, float SPEED, sf::RenderWindow* window, sf::View* camera, const float frames, const sf::Sprite* background, std::vector<Fly> *flies);