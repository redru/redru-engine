#include "StateLevelOneSingle.hpp"

namespace re {

	StateLevelOneSingle::StateLevelOneSingle(RedruEngine& engine) :
		engine(engine),
		gameObjects(12) {
	}

	void StateLevelOneSingle::onInit() {
		background = make_unique<GenericGameObject>(GenericGameObject(engine, engine.getTextureAssets()->loadTexture("TEX_CARD_TABLE")));

		GameEvent event("FROM ON_INIT");

		engine.getEventsManager()->sendEvent(event);
	}

	void StateLevelOneSingle::onClose() {
		background.release();
	}

	void StateLevelOneSingle::update() { }

	void StateLevelOneSingle::fixedUpdate() { }

	void StateLevelOneSingle::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		background->draw(window);
	}

	void StateLevelOneSingle::onInput(sf::Event& event) {
		if (event.type == sf::Event::KeyReleased) {
			switch (event.key.code) {
			case sf::Keyboard::Escape:
				engine.changeState("MAIN_MENU");
				break;
			}
		}
	}

	void StateLevelOneSingle::onEvent(GameEvent& event) {
		spdlog::debug("[StateLevelOneSingle] received event '" + event.getType() + "'");
	}

}
