#pragma once
#include <iostream>
#include <memory>

#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

#include "REDRU/Assets/TextureAssets.hpp"

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

	public:

		sf::RenderWindow& getWindow();

	};

}
