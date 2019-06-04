#pragma once
#include <memory>
#include <iostream>

#include "AudioManager.hpp"
#include "InputManager.hpp"
#include "GraphicsManager.hpp"

namespace re {

	using namespace std;

	class RedruEngine;

	class StatesManager {

	private:

		RedruEngine& engine;

		shared_ptr<AudioManager> audioManager;

		shared_ptr<InputManager> inputManager;

		shared_ptr<GraphicsManager> graphicsManager;


	public:

		StatesManager(RedruEngine& engine);

		void initialize();

		void update();

		void fixedUpdate();

	};

}
