#include "REDRU/Components/GenericButtonObject.hpp"

namespace re {

	GenericButtonObject::GenericButtonObject(string id, RedruEngine& engine) :
		GameObject(id),
		engine(engine),
		buttonText(),
		background() {
	}

	void GenericButtonObject::update() {
	}

	void GenericButtonObject::fixedUpdate() {
	}

	void GenericButtonObject::draw(sf::RenderWindow& window) {
		window.draw(background);
		window.draw(buttonText);
	}

	void GenericButtonObject::onInput(sf::Event& event) {
	}

	void GenericButtonObject::onEvent(re::GameEvent& event) {
	}

	sf::FloatRect GenericButtonObject::getBoundingBox() {
		return background.getGlobalBounds();
	}

	void GenericButtonObject::setPosition(float x, float y) {
		background.setPosition(x, y);

		buttonText.setPosition(x, y);
	}

	void GenericButtonObject::setSize(float x, float y) {
		background.setSize(sf::Vector2f(x, y));
		background.setOrigin(x / 2.f, y / 2.f);
	}

	void GenericButtonObject::setColor(int r, int g, int b, int a) {
		background.setFillColor(sf::Color(r, g, b, a));
	}

	void GenericButtonObject::setText(string text) {
		buttonText.setString(text);

		const sf::FloatRect& bounds = buttonText.getGlobalBounds();
		buttonText.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	}

	void GenericButtonObject::setFontSize(int size) {
		buttonText.setCharacterSize(size);
	}

	void GenericButtonObject::setFont(sf::Font& font) {
		buttonText.setFont(font);
	}

}
