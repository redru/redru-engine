#include "SplashImageObject.hpp"

namespace re {

	SplashImageObject::SplashImageObject(RedruEngine& engine, sf::Texture& texture) :
		engine(engine),
		sprite(texture) {
	}

	void SplashImageObject::update() {
	
	}

	void SplashImageObject::fixedUpdate() {
	}

	void SplashImageObject::draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	void SplashImageObject::onInput(sf::Event event) {
	}

	void SplashImageObject::setPosition(float x, float y) {
		sprite.setPosition(x, y);
	}

	void SplashImageObject::setColor(int r, int g, int b, int a) {
		sprite.setColor(sf::Color(r, g, b, a));
	}

}
