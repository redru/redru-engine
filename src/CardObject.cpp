#include "CardObject.hpp"

namespace re {

	CardObject::CardObject(string id, RedruEngine& engine, sf::Texture& frontTexture, sf::Texture& backTexture, int group) :
		GameObject(id),
		engine(engine),
		frontSprite(frontTexture),
		backSprite(backTexture),
		group(group) {

		const sf::IntRect& size = frontSprite.getTextureRect();
		const sf::Vector2f& position = frontSprite.getPosition();

		frontSprite.setOrigin(size.width / 2.f, size.height / 2.f);
		backSprite.setOrigin(size.width / 2.f, size.height / 2.f);

		selectionBorder.setFillColor(sf::Color::Yellow);
		selectionBorder.setSize(sf::Vector2f(size.width + 4.f, size.height + 4.f));
		selectionBorder.setOrigin((size.width + 4.f) / 2.f, (size.height + 4.f) / 2.f);
	}

	void CardObject::update() { }

	void CardObject::fixedUpdate() { }

	void CardObject::draw(sf::RenderWindow& window) {
		if (selected) window.draw(selectionBorder);

		window.draw(faceUp ? frontSprite : backSprite);
	}

	void CardObject::onInput(sf::Event& event) {
		if (event.type == sf::Event::MouseButtonReleased
			&& frontSprite.getGlobalBounds().contains((float) event.mouseButton.x, (float) event.mouseButton.y)
			&& !locked
			&& !faceUp) {
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
		selectionBorder.setPosition(x, y);
	}

	void CardObject::setColor(int r, int g, int b, int a) {
		frontSprite.setColor(sf::Color(r, g, b, a));
		backSprite.setColor(sf::Color(r, g, b, a));
	}

	void CardObject::flip() {
		faceUp = !faceUp;
	}

	void CardObject::setFaceUp(bool faceUp) {
		this->faceUp = faceUp;
	}

	bool CardObject::isFaceUp() {
		return faceUp;
	}

	void CardObject::setGroup(int group) {
		this->group = group;
	}

	int CardObject::getGroup() {
		return group;
	}

	void CardObject::setLocked(bool locked) {
		this->locked = locked;
	}

	bool CardObject::isLocked() {
		return locked;
	}

	void CardObject::setSelected(bool selected) {
		this->selected = selected;
	}

	bool CardObject::isSelected() {
		return selected;
	}

	bool CardObject::operator==(const CardObject& that) {
		return id == that.id;
	}

}
