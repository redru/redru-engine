#include "REDRU/Components/GenericGameObject.hpp"

namespace re {
	
	GenericGameObject::GenericGameObject(string id, RedruEngine& engine, sf::Texture& texture) :
		GameObject(id),
		engine(engine),
		sprite(texture) {
	}

	void GenericGameObject::update() { }

	void GenericGameObject::fixedUpdate() { }

	void GenericGameObject::draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	void GenericGameObject::onInput(sf::Event& event) { }

	void GenericGameObject::onEvent(GameEvent& event) { }

	sf::FloatRect GenericGameObject::getBoundingBox() {
		return sprite.getGlobalBounds();
	}

	void GenericGameObject::setPosition(float x, float y) {
		sprite.setPosition(x, y);
	}

	void GenericGameObject::setColor(int r, int g, int b, int a) {
		sprite.setColor(sf::Color(r, g, b, a));
	}

}
