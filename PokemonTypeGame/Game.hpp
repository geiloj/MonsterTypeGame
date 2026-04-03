#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.hpp"
#include "Background.hpp"
#include "Input.hpp"
#include "NPC.hpp"
#include "Fly.hpp"
#include "print.hpp"

class Game
{
private:
	Background background;
	std::vector<Npc> enemies;
	Player player;

	sf::RenderWindow window;
	sf::Vector2f center;
	sf::View camera;

	float frame;

	static constexpr int WINDOW_WIDTH = 1920;
	static constexpr int WINDOW_HEIGHT = 1080;
	
	static constexpr int FRAMERATE_LIMIT = 60;
	static constexpr int MAX_ENEMIES = 100;

public:
	int run();
	Game() : frame(0), enemies(MAX_ENEMIES) {}
};