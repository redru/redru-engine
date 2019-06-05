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

	void SplashImageObject::setPosition(float x, float y) {

	}

}
