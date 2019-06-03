#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "REDRU/Managers/AudioManager.hpp"
#include "REDRU/Managers/GraphicsManager.hpp"
#include "REDRU/Managers/InputManager.hpp"
#include "REDRU/Managers/StatesManager.hpp"

namespace re {

	using namespace std;

	class RedruEngine {

	private:
		
		unique_ptr<GraphicsManager> graphicsManager;
		
		unique_ptr<AudioManager> audioManager;
		
		unique_ptr<InputManager> inputManager;

		unique_ptr<StatesManager> statesManager;

	public:
		
		RedruEngine();

		void initialize();

		int start();

	public:

		GraphicsManager& getGraphicsManager();
		
		AudioManager& getAudioManager();

		InputManager& getInputManager();

		StatesManager& getStatesManager();

	};

}
