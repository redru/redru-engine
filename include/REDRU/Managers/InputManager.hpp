#pragma once
#include <iostream>
#include <memory>

#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

#include "REDRU/Managers/GraphicsManager.hpp"

namespace re {

	using namespace std;

	class RedruEngine;

	class InputManager {

	private:

		RedruEngine& engine;

		shared_ptr<GraphicsManager> graphicsManager;


	public:

		InputManager(RedruEngine& engine);

		void initialize();

		void handleWindowEvents();

	};

}
