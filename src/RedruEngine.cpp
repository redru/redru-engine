#include "REDRU/RedruEngine.hpp"

namespace re {

	RedruEngine::RedruEngine() {
		graphicsManager.reset(new GraphicsManager(*this));
		audioManager.reset(new AudioManager(*this));
		inputManager.reset(new InputManager(*this));
	}

	void RedruEngine::initialize() {
		graphicsManager->initialize();
		audioManager->initialize();
		inputManager->initialize();
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

}
