#include "REDRU/Assets/SoundAssets.hpp"

namespace re {

	SoundAssets::SoundAssets(RedruEngine& engine) : engine(engine) {
		spdlog::debug("[SoundAssets] -- created --");
	}

	void SoundAssets::initialize() {
		spdlog::debug("[SoundAssets] -- initialized --");
	}

	void SoundAssets::registerAsset(string name, string file) {
		soundsMapping[name] = file;

		spdlog::debug("[SoundAssets] registered sound '" + name + "' to file '" + file + "'");
	}

	sf::SoundBuffer& SoundAssets::loadSoundBuffer(string name) {
		auto it = soundsMapping.find(name);

		if (it == soundsMapping.end()) {
			spdlog::error("[SoundAssets] sound buffer '" + name + "' was not registered");

			exit(1);
		}

		// Load from cache if present
		auto it2 = loadedBuffers.find(name);

		if (it2 != loadedBuffers.end()) {
			spdlog::debug("[SoundAssets] sound buffer '" + name + "' was loaded from cache");

			return *(it2->second);
		}

		sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();

		if (!soundBuffer->loadFromFile(it->second)) {
			spdlog::error("[SoundAssets] sound buffer '" + name + "' was not found");

			exit(1);
		}

		// Put in cache
		loadedBuffers[name] = make_unique<sf::SoundBuffer>(*soundBuffer);

		return *soundBuffer;
	}

	void SoundAssets::clearCache() {
		loadedBuffers.clear();

		spdlog::debug("[SoundAssets] sound buffers cache was cleared");
	}

}
