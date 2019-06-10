#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <memory>

#include <spdlog/spdlog.h>

#include "REDRU/Assets/TextureAssets.hpp"
#include "REDRU/Components/State.hpp"
#include "REDRU/Managers/AudioManager.hpp"
#include "REDRU/Managers/EventsManager.hpp"
#include "REDRU/Managers/GraphicsManager.hpp"
#include "REDRU/Managers/InputManager.hpp"
#include "REDRU/Managers/StatesManager.hpp"

namespace re {

	using namespace std;

	class RedruEngine {

	private:

		// Assets
		shared_ptr<TextureAssets> textureAssets;
		
		// Managers
		shared_ptr<GraphicsManager> graphicsManager;
		
		shared_ptr<AudioManager> audioManager;

		shared_ptr<EventsManager> eventsManager;
		
		shared_ptr<InputManager> inputManager;

		shared_ptr<StatesManager> statesManager;

		// Engine components
		sf::Clock clock;

		// Members
		int elapsed;

		int elapsedFromLast;

		bool running;

	public:
		
		RedruEngine();

		void initialize();

		int start();

		void registerState(string name, shared_ptr<State> state);

		void changeState(string name, bool immediate = false);

		void registerTexture(string name, string file);

		void stop();

	public:

		int getElapsed();

		int getElpasedFromLast();

	public:

		shared_ptr<TextureAssets> getTextureAssets();

		shared_ptr<GraphicsManager> getGraphicsManager();
		
		shared_ptr<AudioManager> getAudioManager();

		shared_ptr<EventsManager> getEventsManager();

		shared_ptr<InputManager> getInputManager();

		shared_ptr<StatesManager> getStatesManager();

	};

}
