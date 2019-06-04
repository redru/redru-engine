#include "REDRU/RedruEngine.hpp"

namespace re {

	RedruEngine::RedruEngine() {
		graphicsManager.reset(new GraphicsManager(*this));
		audioManager.reset(new AudioManager(*this));
		inputManager.reset(new InputManager(*this));
		statesManager.reset(new StatesManager(*this));
	}

	void RedruEngine::initialize() {
		graphicsManager->initialize();
		audioManager->initialize();
		inputManager->initialize();
		statesManager->initialize();
	}

	int RedruEngine::start() {
		while (graphicsManager->isWindowOpen()) {
			sf::Event event;

			inputManager->handleWindowEvents();

			graphicsManager->draw();
		}

		return 0;
	}

	shared_ptr<GraphicsManager> RedruEngine::getGraphicsManager() {
		return graphicsManager;
	}

	shared_ptr<AudioManager> RedruEngine::getAudioManager() {
		return audioManager;
	}

	shared_ptr<InputManager> RedruEngine::getInputManager() {
		return inputManager;
	}

	shared_ptr<StatesManager> RedruEngine::getStatesManager() {
		return statesManager;
	}

}
