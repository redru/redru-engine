#include "REDRU/Managers/AudioManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	AudioManager::AudioManager(RedruEngine& engine) : engine(engine), currentMusic("ANY") {
		spdlog::debug("[AudioManager] -- created --");
	}

	void AudioManager::initialize() {
		musicAssets = engine.getMusicAssets();
		spdlog::debug("[AudioManager] => linked 'MusicAssets'");

		spdlog::debug("[AudioManager] -- initialized --");
	}

	void AudioManager::playMusic(string name, bool restart) {
		if (currentMusic == name && !restart) return;

		if (currentMusic != "ANY") {
			musicAssets->getMusic(currentMusic).stop();
		}
		
		musicAssets->getMusic(name).play();

		currentMusic = name;
	}

	void AudioManager::restartCurrentMusic() {
		musicAssets->getMusic(currentMusic).play();
	}

	void AudioManager::stopMusic() {
		if (currentMusic != "ANY") {
			musicAssets->getMusic(currentMusic).stop();

			currentMusic = "ANY";
		}
	}

}
