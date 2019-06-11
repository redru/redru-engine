#include "REDRU/Managers/AudioManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	AudioManager::AudioManager(RedruEngine& engine) : engine(engine), currentMusic("ANY") {
		spdlog::debug("[AudioManager] -- created --");
	}

	void AudioManager::initialize() {
		musicAssets = engine.getMusicAssets();
		spdlog::debug("[AudioManager] => linked 'MusicAssets'");

		soundAssets = engine.getSoundAssets();
		spdlog::debug("[AudioManager] => linked 'SoundAssets'");

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

	void AudioManager::playSound(string name) {
		auto it = soundsCache.find(name);

		if (it != soundsCache.end()) {
			spdlog::debug("[AudioManager] sound '" + name + "' was loaded from cache");

			it->second->play();
			return;
		}

		sf::Sound* sound = new sf::Sound();
		sound->setBuffer(soundAssets->loadSoundBuffer(name));

		// Put in cache
		soundsCache[name] = make_unique<sf::Sound>(*sound);

		sound->play();
	}

	void AudioManager::clearCache() {
		soundsCache.clear();

		spdlog::debug("[AudioManager] sound cache was cleared");

		soundAssets->clearCache();
	}

}
