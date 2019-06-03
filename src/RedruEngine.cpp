#include "REDRU/RedruEngine.hpp"

namespace re {

	RedruEngine::RedruEngine() {
	}

	void RedruEngine::initialize() {
		graphicsManager.reset(new GraphicsManager(*this));
		audioManager.reset(new AudioManager(*this));
		inputManager.reset(new InputManager(*this));
		statesManager.reset(new StatesManager(*this));
		

		graphicsManager->initialize();
		audioManager->initialize();
		inputManager->initialize();
		statesManager->initialize();
	}

	int RedruEngine::start() {
		while (graphicsManager->isWindowOpen()) {
			sf::Event event;

			inputManager->handleInput();

			graphicsManager->draw();
		}

		return 0;
	}

	GraphicsManager& RedruEngine::getGraphicsManager() {
		return *graphicsManager;
	}

	AudioManager& RedruEngine::getAudioManager() {
		return *audioManager;
	}

	InputManager& RedruEngine::getInputManager() {
		return *inputManager;
	}

	StatesManager& RedruEngine::getStatesManager() {
		return *statesManager;
	}

}
