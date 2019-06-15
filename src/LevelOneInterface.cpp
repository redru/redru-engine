#include "LevelOneInterface.hpp"

const int LevelOneInterface::MAX_PLAYERS = 4;
const int LevelOneInterface::DUEL = 2;

LevelOneInterface::LevelOneInterface(re::RedruEngine& engine) :
	engine(engine),
	status() {
}

void LevelOneInterface::initialize() {
	sf::Font& uiFont = engine.getFontAssets()->getFont("UI_FONT");

	Players& players = status->getPlayers();

	textPlayer1.setFont(uiFont);
	textPlayer1.setPosition(70.f, 70.f);
	textPlayer1.setCharacterSize(36);
	textPlayer1.setString(players[0]->name);

	textPlayer1Points.setFont(uiFont);
	textPlayer1Points.setPosition(70.f, 106.f);
	textPlayer1Points.setCharacterSize(36);
	textPlayer1Points.setString(to_string(players[0]->points));

	textPlayer2.setFont(uiFont);
	textPlayer2.setPosition(1700.f, 70.f);
	textPlayer2.setCharacterSize(36);
	textPlayer2.setString(players[1]->name);

	textPlayer2Points.setFont(uiFont);
	textPlayer2Points.setPosition(1800.f, 106.f);
	textPlayer2Points.setCharacterSize(36);
	textPlayer2Points.setString(to_string(players[1]->points));

	selectionArrow.setFont(uiFont);
	selectionArrow.setCharacterSize(36);
}

void LevelOneInterface::update() {
	Players& players = status->getPlayers();

	textPlayer1Points.setString(to_string(players[0]->points));
	textPlayer2Points.setString(to_string(players[1]->points));

	int elapsed = animationClock.getElapsedTime().asMilliseconds();

	if (status->getCurrentPlayer() == 0) {
		selectionArrow.setPosition(210.f + elapsed / 20, 70.f);
		selectionArrow.setString("<<<");
	}
	else {
		selectionArrow.setPosition(1600.f + elapsed / 20, 70.f);
		selectionArrow.setString(">>>");
	}

	if (elapsed >= 500) animationClock.restart();
}

void LevelOneInterface::draw() {
	sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

	window.draw(textPlayer1);
	window.draw(textPlayer1Points);

	switch (status->getPlayersCount()) {
	case DUEL:
		window.draw(textPlayer2);
		window.draw(textPlayer2Points);
		break;
	}

	window.draw(selectionArrow);
}

void LevelOneInterface::setStatus(shared_ptr<StateStatus> status) {
	this->status = status;
}
