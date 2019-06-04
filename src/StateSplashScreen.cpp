#include "StateSplashScreen.hpp"

namespace re {

	StateSplashScreen::StateSplashScreen(RedruEngine& engine) :
		engine(engine),
		splashScreenTexture(),
		splashScren() {
	}

	void StateSplashScreen::onInit() {
		splashScreenTexture = make_unique<sf::Texture>(engine.getTextureAssets()->loadTexture("SPLASH_IMAGE"));

		splashScren = make_unique<sf::Sprite>(sf::Sprite(*splashScreenTexture));
	}

	void StateSplashScreen::onClose() {
		splashScren.release();
		splashScreenTexture.release();
	}

	void StateSplashScreen::update() {
		if (clock.getElapsedTime().asMilliseconds() > 3000) engine.changeState("MAIN_MENU");
	}

	void StateSplashScreen::fixedUpdate() {

	}

	void StateSplashScreen::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		window.draw(*splashScren);
	}

}
