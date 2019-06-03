#pragma once
#include <SFML/Graphics.hpp>

namespace re {

	using namespace std;

	class RedruEngine;

	class InputManager {

	private:
		RedruEngine& engine;


	public:
		InputManager(RedruEngine& engine);

		void initialize();

		void handleInput();

	};

}
