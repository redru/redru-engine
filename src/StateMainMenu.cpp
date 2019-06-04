#include "StateMainMenu.hpp"

namespace re {

	StateMainMenu::StateMainMenu(RedruEngine& engine) : engine(engine), shape() {
	}

	void StateMainMenu::onInit() {
		shape.reset(new sf::RectangleShape(sf::Vector2f(60.f, 60.f)));

		shape->setFillColor(sf::Color::Green);
		shape->setOrigin(30.f, 30.f);
		shape->setPosition(400.f, 400.f);
	}

	void StateMainMenu::onClose() {
		shape.release();
	}

	void StateMainMenu::update() {
		
	}

	void StateMainMenu::fixedUpdate() {

	}

	void StateMainMenu::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		window.draw(*shape);
	}

}