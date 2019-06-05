#include "StateSplashScreen.hpp"

namespace re {

	StateSplashScreen::StateSplashScreen(RedruEngine& engine) :
		engine(engine),
		splashImage() {
	}

	void StateSplashScreen::onInit() {
		splashImage = make_unique<SplashImageObject>(SplashImageObject(engine, engine.getTextureAssets()->loadTexture("TEX_SPLASH_IMAGE")));
	}

	void StateSplashScreen::onClose() {
		splashImage.release();
	}

	void StateSplashScreen::update() {
		int elapsed = clock.getElapsedTime().asMilliseconds();

		float alpha = elapsed > 1000 ? 255 : elapsed * 255 / 1000;

		splashImage->setColor(255.f, 255.f, 255.f, alpha);

		if (clock.getElapsedTime().asMilliseconds() > 3000) engine.changeState("MAIN_MENU");
	}

	void StateSplashScreen::fixedUpdate() {

	}

	void StateSplashScreen::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		splashImage->draw(window);
	}

}
