#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <memory>

#include <spdlog/spdlog.h>

#include "REDRU/Components/State.hpp"
#include "REDRU/Managers/AudioManager.hpp"
#include "REDRU/Managers/GraphicsManager.hpp"
#include "REDRU/Managers/InputManager.hpp"
#include "REDRU/Managers/StatesManager.hpp"

namespace re {

	using namespace std;

	class RedruEngine {

	private:
		
		// Managers
		shared_ptr<GraphicsManager> graphicsManager;
		
		shared_ptr<AudioManager> audioManager;
		
		shared_ptr<InputManager> inputManager;

		shared_ptr<StatesManager> statesManager;

		// Engine components
		sf::Clock clock;

		// Members
		int elapsed;

	public:
		
		RedruEngine();

		void initialize();

		int start();

		void registerState(string name, shared_ptr<State> state);

		void changeState(string name, bool immediate = false);

	public:

		int getElapsed();

	public:

		shared_ptr<GraphicsManager> getGraphicsManager();
		
		shared_ptr<AudioManager> getAudioManager();

		shared_ptr<InputManager> getInputManager();

		shared_ptr<StatesManager> getStatesManager();

	};

}
