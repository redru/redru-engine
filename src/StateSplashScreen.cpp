#include "StateSplashScreen.hpp"

namespace re {

	StateSplashScreen::StateSplashScreen(RedruEngine& engine) : engine(engine), shape() {
	}

	void StateSplashScreen::onInit() {
		shape.reset(new sf::RectangleShape(sf::Vector2f(60.f, 60.f)));

		shape->setFillColor(sf::Color::Blue);
		shape->setOrigin(30.f, 30.f);
		shape->setPosition(200.f, 200.f);

		clock.restart();
	}

	void StateSplashScreen::onClose() {
		shape.release();
	}

	void StateSplashScreen::update() {
		if (clock.getElapsedTime().asMilliseconds() > 3000) engine.changeState("MAIN_MENU");
	}

	void StateSplashScreen::fixedUpdate() {

	}

	void StateSplashScreen::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		window.draw(*shape);
	}

}
