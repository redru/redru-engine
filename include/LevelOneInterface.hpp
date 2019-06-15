#pragma once
#include <ctime>
#include <math.h>

#include <SFML/Graphics.hpp>

#include "REDRU/RedruEngine.hpp"
#include "StateStatus.hpp"

using namespace std;

class LevelOneInterface {

private:

	static const int SINGLE;
	static const int DUEL;
	static const int CAOS;

	static const int ARROW_TIME;

	re::RedruEngine& engine;

	shared_ptr<StateStatus> status;

	sf::Clock animationClock;

	sf::Font font;

	sf::Text textPlayer1;
	sf::Text textPlayer1Points;

	sf::Text textPlayer2;
	sf::Text textPlayer2Points;

	sf::Text selectionArrow;

public:

	LevelOneInterface(re::RedruEngine& engine);

	void initialize();

	void update();

	void draw();

	void setStatus(shared_ptr<StateStatus> status);

};
