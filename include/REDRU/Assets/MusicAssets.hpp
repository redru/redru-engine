#pragma once
#include <map>
#include <memory>
#include <string>

#include <spdlog/spdlog.h>
#include <SFML/Audio.hpp>

namespace re {
	
	using namespace std;

	class RedruEngine;

	typedef map<string, unique_ptr<sf::Music>> Musics;

	class MusicAssets {

	private:

		RedruEngine& engine;

		Musics musicStreamers;

	public:

		MusicAssets(RedruEngine& engine);

		void initialize();

		void registerAsset(string name, string file);

		sf::Music& getMusic(string name);

	};

}
