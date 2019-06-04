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

		clock.restart();

		while ((statesManager->hasActiveState() && graphicsManager->isWindowOpen())) {
			if (statesManager->hasRequestedState()) statesManager->nextState();

			elapsed = clock.getElapsedTime().asMilliseconds();

			if (elapsed < realTimeToNext) {
				// Exceute update
				statesManager->update();

				continue;
			}

			// Execute fixed update
			statesManager->fixedUpdate();

			// Take time again after updates
			elapsed = clock.getElapsedTime().asMilliseconds();

			// Take the exceded time
			float exceded = elapsed - realTimeToNext;

			if (exceded > timeToNext) { // If exceded the full frame time, skip 1
				cout << "[RedruEngine] skipped 1 frame" << endl;
				realTimeToNext = timeToNext;
			}
			else { // Substract the exceded from the full frame time
				realTimeToNext = timeToNext - exceded;
			}

			clock.restart();
		}

		return 0;
	}

	void RedruEngine::registerState(string name, shared_ptr<State> state) {
		statesManager->registerState(name, state);
	}

	void RedruEngine::changeState(string name, bool immediate) {
		statesManager->requestStateChange(name);

		if (immediate) statesManager->nextState();
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
