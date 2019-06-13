#include "LevelOneInterface.hpp"

namespace re {

	LevelOneInterface::LevelOneInterface(RedruEngine& engine, int players) :
		engine(engine),
		players(players) {

		sf::Font& uiFont = engine.getFontAssets()->getFont("UI_FONT");

		textPlayer1.setFont(uiFont);
		textPlayer1.setPosition(70.f, 70.f);
		textPlayer1.setCharacterSize(36);
		textPlayer1.setString("Player 1 ->");

		textPlayer2.setFont(uiFont);
		textPlayer2.setPosition(1700.f, 70.f);
		textPlayer2.setCharacterSize(36);
		textPlayer2.setString("<- Player 2");
	}

	void LevelOneInterface::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		window.draw(textPlayer1);

		switch (players) {
		case 2:
			window.draw(textPlayer2);
			break;
		}
	}

}
