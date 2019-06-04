#pragma once
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"

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
