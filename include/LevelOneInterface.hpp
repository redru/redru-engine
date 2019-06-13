#pragma once
#include <SFML/Graphics.hpp>

#include "REDRU/RedruEngine.hpp"

namespace re {

	using namespace std;

	class LevelOneInterface {

	private:

		RedruEngine& engine;

		int players;

		sf::Font font;

		sf::Text textPlayer1;

		sf::Text textPlayer2;

	public:

		LevelOneInterface(RedruEngine& engine, int players = 1);

		void draw();

	};

}
