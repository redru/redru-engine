#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>

#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

namespace re {

	using namespace std;

	class RedruEngine;

	typedef map<string, unique_ptr<sf::Texture>> Textures;

	class TextureAssets {

	private:

		RedruEngine& engine;

		map<string, string> texturesMapping;

		Textures loadedTextures;

	public:

		TextureAssets(RedruEngine& engine);

		void initialize();

		void registerAsset(string name, string file);

		sf::Texture& loadTexture(string name);

		void clearCache();

	};

}
