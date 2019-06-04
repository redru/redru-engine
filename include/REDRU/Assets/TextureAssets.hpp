#pragma once
#include <iostream>
#include <map>
#include <string>

#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

namespace re {

	using namespace std;

	class RedruEngine;

	class TextureAssets {

	private:

		RedruEngine& engine;

		map<string, string> texturesMapping;

	public:

		TextureAssets(RedruEngine& engine);

		void initialize();

		void registerAsset(string name, string file);

		sf::Texture& loadTexture(string name);

	};

}
