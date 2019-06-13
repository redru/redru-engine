#pragma once
#include <SFML/Graphics.hpp>

#include "REDRU/RedruEngine.hpp"
#include "StateStatus.hpp"

namespace re {

	using namespace std;

	class LevelOneInterface {

	private:

		static const int MAX_PLAYERS;

		static const int DUEL;

		RedruEngine& engine;

		shared_ptr<StateStatus> status;

		sf::Font font;

		sf::Text textPlayer1;
		sf::Text textPlayer1Points;

		sf::Text textPlayer2;
		sf::Text textPlayer2Points;

	public:

		LevelOneInterface(RedruEngine& engine);

		void initialize();

		void draw();

		void setStatus(shared_ptr<StateStatus> status);

	};

}
