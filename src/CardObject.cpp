#include "CardObject.hpp"

namespace re {

	CardObject::CardObject(string id, RedruEngine& engine, sf::Texture& frontTexture, sf::Texture& backTexture, int group) :
		GameObject(id),
		engine(engine),
		frontSprite(frontTexture),
		backSprite(backTexture),
		group(group) {

		const sf::IntRect& size = frontSprite.getTextureRect();

		frontSprite.setOrigin(size.width / 2, size.height / 2);
		backSprite.setOrigin(size.width / 2, size.height / 2);
	}

	void CardObject::update() { }

	void CardObject::fixedUpdate() { }

	void CardObject::draw(sf::RenderWindow& window) {
		window.draw(faceUp ? frontSprite : backSprite);
	}

	void CardObject::onInput(sf::Event& event) {
		if (event.type == sf::Event::MouseButtonReleased && frontSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			faceUp = !faceUp;

			GameEvent event("CARD_FLIPPED");
			event.setSource(this);

			engine.getEventsManager()->sendEvent(event);
		}
	}

	void CardObject::onEvent(GameEvent& event) { }

	sf::FloatRect CardObject::getBoundingBox() {
		return frontSprite.getGlobalBounds();
	}

	void CardObject::setPosition(float x, float y) {
		frontSprite.setPosition(x, y);
		backSprite.setPosition(x, y);
	}

	void CardObject::setColor(int r, int g, int b, int a) {
		frontSprite.setColor(sf::Color(r, g, b, a));
		backSprite.setColor(sf::Color(r, g, b, a));
	}

	void CardObject::setFaceUp(bool faceUp) {
		this->faceUp = faceUp;
	}

	bool& CardObject::isFaceUp() {
		return faceUp;
	}

	void CardObject::setGroup(int group) {
		this->group = group;
	}

	int& CardObject::getGroup() {
		return group;
	}

}
