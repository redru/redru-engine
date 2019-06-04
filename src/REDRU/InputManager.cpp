#include "REDRU/Managers/InputManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	InputManager::InputManager(RedruEngine& engine) : engine(engine) {
		spdlog::debug("[InputManager] -- created --");
	}

	void InputManager::initialize() {
		graphicsManager = engine.getGraphicsManager();
		spdlog::debug("[InputManager] => linked 'GraphicsManager'");

		spdlog::debug("[InputManager] -- initialized --");
	}

	void InputManager::handleWindowEvents() {
		sf::Event event;

		while (graphicsManager->nextEvent(event)) {
			if (event.type == sf::Event::Closed) graphicsManager->closeWindow();
		}
	}

}
