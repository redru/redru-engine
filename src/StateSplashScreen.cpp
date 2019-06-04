#include "StateSplashScreen.hpp"

namespace re {

	StateSplashScreen::StateSplashScreen(RedruEngine& engine) : engine(engine), shape() {
	}

	void StateSplashScreen::onInit() {
		shape.reset(new sf::RectangleShape(sf::Vector2f(60.f, 60.f)));

		shape->setFillColor(sf::Color::Blue);
		shape->setOrigin(30.f, 30.f);
		shape->setPosition(200.f, 200.f);
	}

	void StateSplashScreen::onClose() {
		shape.release();
	}

	void StateSplashScreen::update() {

	}

	void StateSplashScreen::fixedUpdate() {

	}

	void StateSplashScreen::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		window.draw(*shape);
	}

}
