#include "Button.hpp"

namespace re {

	Button::Button(sf::Texture& texture, string text) : sprite(texture), textElement() {
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
			spdlog::error("[Button] font 'C:\\Windows\\Fonts\\arial.ttf' was not found");

			exit(1);
		}

		textElement.setFont(font);
		textElement.setString(text);
	}

	void Button::update() {

	}

	void Button::fixedUpdate() {

	}

	void Button::draw(sf::RenderWindow& window) {
		window.draw(sprite);
		window.draw(textElement);
	}

	void Button::setPosition(float x, float y) {
		sprite.setPosition(x, y);
		// textElement.setPosition(x, y);
	}

}
