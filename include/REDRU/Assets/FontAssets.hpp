#pragma once
#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

namespace re {

	using namespace std;

	class RedruEngine;

	typedef map<string, unique_ptr<sf::Font>> Fonts;

	class FontAssets {

	private:

		RedruEngine& engine;

		Fonts fonts;

	public:

		FontAssets(RedruEngine& engine);

		void initialize();

		void registerAsset(string name, string file);

		sf::Font& getFont(string name);

	};

}
