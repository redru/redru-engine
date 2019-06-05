#include "StateMainMenu.hpp"

namespace re {

	StateMainMenu::StateMainMenu(RedruEngine& engine) :
		engine(engine),
		mainMenuImage() {
	}

	void StateMainMenu::onInit() {
		mainMenuImage = make_unique<sf::Sprite>(sf::Sprite(engine.getTextureAssets()->loadTexture("TEX_MAIN_MENU")));
		startButton = make_unique<sf::Sprite>(sf::Sprite(engine.getTextureAssets()->loadTexture("TEX_START_BUTTON")));
		exitButton = make_unique<sf::Sprite>(sf::Sprite(engine.getTextureAssets()->loadTexture("TEX_EXIT_BUTTON")));

		startButton->setPosition(200.f, 180.f);
		exitButton->setPosition(200.f, 240.f);
	}

	void StateMainMenu::onClose() {
		mainMenuImage.release();
		startButton.release();
		exitButton.release();
	}

	void StateMainMenu::update() {
		
	}

	void StateMainMenu::fixedUpdate() {

	}

	void StateMainMenu::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		window.draw(*mainMenuImage);
		window.draw(*startButton);
		window.draw(*exitButton);
	}

	void StateMainMenu::onInput(sf::Event& event) {
		if (event.type == sf::Event::KeyReleased) {
			switch (event.key.code) {
			case sf::Keyboard::Escape:
				engine.stop();
				break;
			
			case sf::Keyboard::Enter:
				engine.changeState("LEVEL_ONE_SINGLE");
				break;
			}
		} else if (event.type == sf::Event::MouseButtonPressed) {
			if (startButton->getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
				engine.changeState("LEVEL_ONE_SINGLE");
			} else if (exitButton->getGlobalBounds().contains((float) event.mouseButton.x, (float) event.mouseButton.y)) {
				engine.stop();
			}
		}
	}

	void StateMainMenu::onEvent() {

	}

}
