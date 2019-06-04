#include "REDRU/Managers/StatesManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	StatesManager::StatesManager(RedruEngine& engine) : engine(engine) {
		cout << "[StatesManager] created" << endl;
	}

	void StatesManager::initialize() {
		cout << "[StatesManager]:" << endl;

		audioManager = engine.getAudioManager();
		cout << "  |- linked 'AudioManager'" << endl;

		graphicsManager = engine.getGraphicsManager();
		cout << "  |- linked 'GraphicsManager'" << endl;

		inputManager = engine.getInputManager();
		cout << "  |- linked 'InputManager'" << endl;

		cout << "[StatesManager] initialized" << endl;
	}

}
