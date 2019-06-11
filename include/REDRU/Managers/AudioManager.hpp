#pragma once
#include <string>
#include <map>

#include <SFML/Audio.hpp>
#include <spdlog/spdlog.h>

#include "REDRU/Assets/MusicAssets.hpp"
#include "REDRU/Assets/SoundAssets.hpp"

namespace re {

	using namespace std;

	class RedruEngine;

	typedef map<string, unique_ptr<sf::Sound>> Sounds;

	class AudioManager {

	private:

		RedruEngine& engine;

		shared_ptr<MusicAssets> musicAssets;

		shared_ptr<SoundAssets> soundAssets;

		string currentMusic;

		Sounds soundsCache;

	public:

		AudioManager(RedruEngine& engine);

		void initialize();

		void playMusic(string name, bool restart = false);

		void restartCurrentMusic();

		void stopMusic();

		void playSound(string name);

		void clearCache();

	};

}
