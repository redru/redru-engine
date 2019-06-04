#include "REDRU/Managers/StatesManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	StatesManager::StatesManager(RedruEngine& engine) : engine(engine) {
		cout << "[StatesManager] -- created --" << endl;
	}

	void StatesManager::initialize() {
		audioManager = engine.getAudioManager();
		cout << "[StatesManager] => linked 'AudioManager'" << endl;

		graphicsManager = engine.getGraphicsManager();
		cout << "[StatesManager] => linked 'GraphicsManager'" << endl;

		inputManager = engine.getInputManager();
		cout << "[StatesManager] => linked 'InputManager'" << endl;

		cout << "[StatesManager] -- initialized --" << endl;
	}

	void StatesManager::update() {
		cout << "[RedruEngine] update" << endl;
		cout << "[RedruEngine] elapsed time: " + to_string(engine.getElapsed()) << endl;

		inputManager->handleWindowEvents();
	}

	void StatesManager::fixedUpdate() {
		cout << "[RedruEngine] fixed update" << endl;
		cout << "[RedruEngine] elapsed time: " + to_string(engine.getElapsed()) << endl;

		graphicsManager->draw();
	}

}
