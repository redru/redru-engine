#include "REDRU/RedruEngine.hpp"

namespace re {

	RedruEngine::RedruEngine() :
		clock(sf::Clock()),
		elapsed(0),
		running(true)
	{
		textureAssets = make_shared<TextureAssets>(TextureAssets(*this));
		graphicsManager = make_shared<GraphicsManager>(GraphicsManager(*this));
		audioManager = make_shared<AudioManager>(AudioManager(*this));
		inputManager = make_shared<InputManager>(InputManager(*this));
		statesManager = make_shared<StatesManager>(StatesManager(*this));
	}

	void RedruEngine::initialize() {
		textureAssets->initialize();
		graphicsManager->initialize();
		audioManager->initialize();
		inputManager->initialize();
		statesManager->initialize();
	}

	int RedruEngine::start() {
		float timeToNext = ceil(1000.f / 30.f);
		float realTimeToNext = 0;

		clock.restart();

		while ((running && statesManager->hasActiveState() && graphicsManager->isWindowOpen())) {
			// Check if a new state has been requested, then change it
			if (statesManager->hasRequestedState()) statesManager->nextState();

			// Get the time from las clock reset
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
				spdlog::debug("[RedruEngine] skipped " + to_string(exceded / timeToNext) + " frame");
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
		spdlog::debug("[RedruEngine] requested state change -> '" + name + "' / immediate (" + to_string(immediate) + ")");

		statesManager->requestStateChange(name);

		if (immediate) statesManager->nextState();
	}

	int RedruEngine::getElapsed() {
		return elapsed;
	}

	void RedruEngine::registerTexture(string name, string file) {
		textureAssets->registerAsset(name, file);
	}

	void RedruEngine::stop() {
		running = false;
	}

	shared_ptr<TextureAssets> RedruEngine::getTextureAssets() {
		return textureAssets;
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
