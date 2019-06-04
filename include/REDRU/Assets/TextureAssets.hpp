#pragma once
#include <iostream>
#include <map>
#include <string>

#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

namespace re {

	using namespace std;

	class TextureAssets {

	public:

		TextureAssets();

		void initialize();

		void registerAsset(string name, string file);

		sf::Texture& loadTexture(string name);

	private:

		map<string, string> texturesMapping;

	};

}
