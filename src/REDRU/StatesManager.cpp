#include "REDRU/Managers/StatesManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	StatesManager::StatesManager(RedruEngine& engine) : engine(engine) {
		spdlog::debug("[StatesManager] -- created --");
	}

	void StatesManager::initialize() {
		audioManager = engine.getAudioManager();
		spdlog::debug("[StatesManager] => linked 'AudioManager'");

		graphicsManager = engine.getGraphicsManager();
		spdlog::debug("[StatesManager] => linked 'GraphicsManager'");

		inputManager = engine.getInputManager();
		spdlog::debug("[StatesManager] => linked 'InputManager'");

		spdlog::debug("[StatesManager] -- initialized --");
	}

	void StatesManager::update() {
		sf::Event event;
		
		while (inputManager->handleWindowEvent(event)) {
			activeState->onInput(event);
		}

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

		spdlog::debug("[RedruEngine] registered state '" + name + "'");
	}

	void StatesManager::requestStateChange(string name) {
		States::iterator it = states.find(name);

		if (it == states.end()) {
			spdlog::error("[StatesManager] requested state '" + name + "' does not exists");

			exit(1);
		}

		requestedState = it->second;
	}

	void StatesManager::nextState() {
		// Execute onClose() function on current state
		if (activeState) activeState->onClose();

		// Clear Textures cache
		engine.getTextureAssets()->clearCache();

		// Clear Audio cache
		engine.getAudioManager()->clearCache();

		// Set new state
		activeState = requestedState;

		// Initialize new state
		activeState->onInit();

		// Reset requestedState pointer
		requestedState.reset();
	}

	void StatesManager::onEvent(GameEvent& event) {
		activeState->onEvent(event);
	}

	bool StatesManager::hasActiveState() {
		return !!activeState;
	}

	bool StatesManager::hasRequestedState() {
		return !!requestedState;
	}

}
