#include "REDRU/Managers/AudioManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	AudioManager::AudioManager(RedruEngine& engine) : engine(engine) {
		spdlog::debug("[AudioManager] -- created --");
	}

	void AudioManager::initialize() {
		spdlog::debug("[AudioManager] -- initialized --");
	}

}
