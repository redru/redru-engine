#pragma once
#include <map>
#include <memory>
#include <string>

#include <SFML/Audio.hpp>
#include <spdlog/spdlog.h>

namespace re {

	class RedruEngine;

	using namespace std;

	typedef map<string, unique_ptr<sf::SoundBuffer>> SoundBuffers;

	class SoundAssets {

	private:

		RedruEngine& engine;

		map<string, string> soundsMapping;

		SoundBuffers loadedBuffers;

	public:

		SoundAssets(RedruEngine& engine);

		void initialize();

		void registerAsset(string name, string file);

		sf::SoundBuffer& loadSoundBuffer(string name);

		void clearCache();

	};

}
