#include "REDRU/RedruEngine.hpp"

namespace re {

	RedruEngine::RedruEngine() :
		clock(sf::Clock()),
		elapsed(0),
		running(true)
	{
		musicAssets = make_shared<MusicAssets>(MusicAssets(*this));
		textureAssets = make_shared<TextureAssets>(TextureAssets(*this));
		eventsManager = make_shared<EventsManager>(EventsManager(*this));
		graphicsManager = make_shared<GraphicsManager>(GraphicsManager(*this));
		audioManager = make_shared<AudioManager>(AudioManager(*this));
		inputManager = make_shared<InputManager>(InputManager(*this));
		statesManager = make_shared<StatesManager>(StatesManager(*this));
	}

	void RedruEngine::initialize() {
		musicAssets->initialize();
		textureAssets->initialize();
		eventsManager->initialize();
		graphicsManager->initialize();
		audioManager->initialize();
		inputManager->initialize();
		statesManager->initialize();
	}

	int RedruEngine::start() {
		// 1000 ms / 30 fps
		const float TIME_TO_NEXT = ceil(1000.f / 30.f);
		float realTimeToNext = 0;

		clock.restart();

		while ((running && statesManager->hasActiveState() && graphicsManager->isWindowOpen())) {
			// Check if a new state has been requested, then change it
			if (statesManager->hasRequestedState()) statesManager->nextState();

			// Get the time from las clock reset, set the elapsed from one update to another, and assign elapsed from last frame
			int tmpElapsed = clock.getElapsedTime().asMilliseconds();
			elapsedFromLast = tmpElapsed - elapsed;
			elapsed = tmpElapsed;

			// The above operation can give negative numbers, so fix it
			if (elapsedFromLast < 0) elapsedFromLast = 0;

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

			if (exceded > TIME_TO_NEXT) { // If exceded the full frame time, log it
				spdlog::debug("[RedruEngine] skipped " + to_string(exceded / TIME_TO_NEXT) + " frame");
				realTimeToNext = TIME_TO_NEXT;
			} else { // Substract the exceded from the full frame time
				realTimeToNext = TIME_TO_NEXT - exceded;
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

	int RedruEngine::getElpasedFromLast() {
		return elapsedFromLast;
	}

	void RedruEngine::registerTexture(string name, string file) {
		textureAssets->registerAsset(name, file);
	}

	void RedruEngine::registerMusic(string name, string file) {
		musicAssets->registerAsset(name, file);
	}

	void RedruEngine::stop() {
		running = false;
	}

	shared_ptr<MusicAssets> RedruEngine::getMusicAssets() {
		return musicAssets;
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

	shared_ptr<EventsManager> RedruEngine::getEventsManager() {
		return eventsManager;
	}

	shared_ptr<InputManager> RedruEngine::getInputManager() {
		return inputManager;
	}

	shared_ptr<StatesManager> RedruEngine::getStatesManager() {
		return statesManager;
	}

}
