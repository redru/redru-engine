#include "REDRU/Managers/InputManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	InputManager::InputManager(RedruEngine& engine) : engine(engine) {
	}

	void InputManager::initialize() {
	}

	void InputManager::handleInput() {
		sf::Event event;
		GraphicsManager& graphics = engine.getGraphicsManager();

		while (graphics.nextEvent(event)) {
			if (event.type == sf::Event::Closed) graphics.closeWindow();
		}
	}

}
