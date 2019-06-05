#include "StateLevelOneSingle.hpp"

namespace re {

	StateLevelOneSingle::StateLevelOneSingle(RedruEngine& engine) :
		engine(engine) {
	}

	void StateLevelOneSingle::onInit() {
		
	}

	void StateLevelOneSingle::onClose() {

	}

	void StateLevelOneSingle::update() {
		
	}

	void StateLevelOneSingle::fixedUpdate() {

	}

	void StateLevelOneSingle::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();
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

	void StateLevelOneSingle::onEvent() {

	}

}
