#include "REDRU/RedruEngine.hpp"

namespace re {

	RedruEngine::RedruEngine() : clock(sf::Clock()), elapsed(0) {
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
		float timeToNext = ceil(1000.f / 30.f);
		float realTimeToNext = 0;

		while (graphicsManager->isWindowOpen()) {
			elapsed = clock.getElapsedTime().asMilliseconds();

			if (elapsed < realTimeToNext) {
				statesManager->update();
			} else {
				statesManager->fixedUpdate();

				float exceded = elapsed - realTimeToNext;

				// If we exceded the frame time
				if (exceded != 0) {
					if (exceded > timeToNext) { // If exceded the full frame time, skip 1
						cout << "[RedruEngine] skipped 1 frame" << endl;
						realTimeToNext = timeToNext;
					} else { // Substract the exceded from the full frame time
						realTimeToNext = timeToNext - exceded;
					}
				} else {
					realTimeToNext = timeToNext;
				}

				clock.restart();
			}
		}

		return 0;
	}

	int RedruEngine::getElapsed() {
		return elapsed;
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
