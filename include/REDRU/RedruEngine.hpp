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
		
		shared_ptr<GraphicsManager> graphicsManager;
		
		shared_ptr<AudioManager> audioManager;
		
		shared_ptr<InputManager> inputManager;

		shared_ptr<StatesManager> statesManager;

	public:
		
		RedruEngine();

		void initialize();

		int start();

	public:

		shared_ptr<GraphicsManager> getGraphicsManager();
		
		shared_ptr<AudioManager> getAudioManager();

		shared_ptr<InputManager> getInputManager();

		shared_ptr<StatesManager> getStatesManager();

	};

}
