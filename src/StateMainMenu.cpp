#include "StateMainMenu.hpp"

namespace re {

	StateMainMenu::StateMainMenu(RedruEngine& engine) :
		engine(engine),
		mainMenuImage() {
	}

	void StateMainMenu::onInit() {
		mainMenuImage = make_unique<sf::Sprite>(sf::Sprite(engine.getTextureAssets()->loadTexture("TEX_MAIN_MENU")));
		startButton = make_unique<sf::Sprite>(sf::Sprite(engine.getTextureAssets()->loadTexture("TEX_START_BUTTON")));

		startButton->setPosition(200.f, 180.f);
	}

	void StateMainMenu::onClose() {
		mainMenuImage.release();
		startButton.release();
	}

	void StateMainMenu::update() {
		
	}

	void StateMainMenu::fixedUpdate() {

	}

	void StateMainMenu::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		window.draw(*mainMenuImage);
		window.draw(*startButton);
	}

	void StateMainMenu::onInput(sf::Event& event) {

	}

	void StateMainMenu::onEvent() {

	}

}