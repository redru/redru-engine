#pragma once
#include <string>
#include <spdlog/spdlog.h>

#include "REDRU/Assets/MusicAssets.hpp"
#include "REDRU/Assets/SoundAssets.hpp"

namespace re {

	using namespace std;

	class RedruEngine;

	class AudioManager {

	private:

		RedruEngine& engine;

		shared_ptr<MusicAssets> musicAssets;

		string currentMusic;

	public:

		AudioManager(RedruEngine& engine);

		void initialize();

		void playMusic(string name);

	};

}
