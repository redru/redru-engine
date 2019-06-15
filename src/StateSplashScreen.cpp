#include "StateSplashScreen.hpp"

namespace re {

	StateSplashScreen::StateSplashScreen(RedruEngine& engine) :
		engine(engine) {
	}

	void StateSplashScreen::onInit() {
		elapsed = 0;

		splashImage = make_unique<GenericGameObject>(GenericGameObject("SPLASH", engine, engine.getTextureAssets()->loadTexture("TEX_SPLASH_IMAGE")));

		splashImage->setColor(255, 255, 255, 0);
	}

	void StateSplashScreen::onClose() {
		splashImage.release();
	}

	void StateSplashScreen::reset() { }

	void StateSplashScreen::update() {
		elapsed += engine.getElpasedFromLast();

		int alpha = elapsed >= 1000 ? 255 : (int) round(elapsed * 255 / 1000);

		splashImage->setColor(255, 255, 255, alpha);

		if (elapsed > 3000) engine.changeState("MAIN_MENU");
	}

	void StateSplashScreen::fixedUpdate() {

	}

	void StateSplashScreen::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		splashImage->draw(window);
	}

	void StateSplashScreen::onInput(sf::Event& event) {
		if (event.type == sf::Event::KeyReleased) {
			switch (event.key.code) {
			case sf::Keyboard::Escape:
				engine.stop();
				break;

			case sf::Keyboard::Space:
				engine.changeState("MAIN_MENU");
				break;
			}
		}
	}

	void StateSplashScreen::onEvent(GameEvent& event) {

	}

}
