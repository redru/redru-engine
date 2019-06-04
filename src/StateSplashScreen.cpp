#include "StateSplashScreen.hpp"

namespace re {

	StateSplashScreen::StateSplashScreen(RedruEngine& engine) :
		engine(engine),
		splashImage() {
	}

	void StateSplashScreen::onInit() {
		splashImage = make_unique<SplashImageObject>(SplashImageObject(engine, engine.getTextureAssets()->loadTexture("SPLASH_IMAGE")));
	}

	void StateSplashScreen::onClose() {
		splashImage.release();
	}

	void StateSplashScreen::update() {
		if (clock.getElapsedTime().asMilliseconds() > 3000) engine.changeState("MAIN_MENU");
	}

	void StateSplashScreen::fixedUpdate() {

	}

	void StateSplashScreen::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		splashImage->draw(window);
	}

}
