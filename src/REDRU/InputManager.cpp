#include "REDRU/Managers/InputManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	InputManager::InputManager(RedruEngine& engine) : engine(engine) {
		cout << "[InputManager] -- created --" << endl;
	}

	void InputManager::initialize() {
		graphicsManager = engine.getGraphicsManager();
		cout << "[InputManager] => linked 'GraphicsManager'" << endl;

		cout << "[InputManager] -- initialized --" << endl;
	}

	void InputManager::handleWindowEvents() {
		sf::Event event;

		while (graphicsManager->nextEvent(event)) {
			if (event.type == sf::Event::Closed) graphicsManager->closeWindow();
		}
	}

}
