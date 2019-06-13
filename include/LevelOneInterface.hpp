#pragma once
#include <SFML/Graphics.hpp>

#include "REDRU/RedruEngine.hpp"

namespace re {

	using namespace std;

	class LevelOneInterface {

	private:

		RedruEngine& engine;

		sf::Font font;

		sf::Text text;

	public:

		LevelOneInterface(RedruEngine& engine);

		void draw();

	};

}
