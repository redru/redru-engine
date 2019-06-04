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
		inputManager->handleWindowEvents();

		activeState->update();
	}

	void StatesManager::fixedUpdate() {
		sf::RenderWindow& window = graphicsManager->getWindow();

		activeState->fixedUpdate();

		window.clear();

		activeState->draw();

		window.display();
	}

	void StatesManager::registerState(string name, shared_ptr<State> state) {
		states[name] = state;
	}

	void StatesManager::requestStateChange(string name) {
		shared_ptr<State>& tmp = states[name];

		if (!tmp) {
			cout << "[StatesManager] requested state '" + name + "' does not exists" << endl;

			exit(1);
		}

		requestedState = tmp;
	}

	void StatesManager::nextState() {
		if (activeState) activeState->onClose();

		activeState = requestedState;

		activeState->onInit();

		requestedState.reset();
	}

	bool StatesManager::hasActiveState() {
		return !!activeState;
	}

	bool StatesManager::hasRequestedState() {
		return !!requestedState;
	}

}
