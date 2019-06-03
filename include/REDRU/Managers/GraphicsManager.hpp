#pragma once
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

namespace re {

	using namespace std;

	class RedruEngine;

	class GraphicsManager {

	private:
		RedruEngine& engine;
		unique_ptr<sf::RenderWindow> window;


	public:
		GraphicsManager(RedruEngine& engine);

		void initialize();

		bool isWindowOpen();

		bool nextEvent(sf::Event& event);

		void closeWindow();

		void draw();

	};

}
