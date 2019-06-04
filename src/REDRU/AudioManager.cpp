#include "REDRU/Managers/AudioManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	AudioManager::AudioManager(RedruEngine& engine) : engine(engine) {
		cout << "[AudioManager] -- created --" << endl;
	}

	void AudioManager::initialize() {
		cout << "[AudioManager] -- initialized --" << endl;
	}

}