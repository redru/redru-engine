#include "REDRU/Assets/MusicAssets.hpp"

namespace re {

	MusicAssets::MusicAssets(RedruEngine& engine) : engine(engine), musicStreamers() {
		spdlog::debug("[MusicAssets] -- created --");
	}

	void MusicAssets::initialize() {
		spdlog::debug("[MusicAssets] -- initialized --");
	}

	void MusicAssets::registerAsset(string name, string file) {
		sf::Music* music = new sf::Music();
		music->setLoop(true);

		if (!music->openFromFile(file)) {
			spdlog::debug("[MusicAssets] music file '" + file + "' was not found");

			exit(1);
		}

		musicStreamers[name] = unique_ptr<sf::Music>(music);

		spdlog::debug("[MusicAssets] registered music '" + name + "' to file '" + file + "'");
	}

	sf::Music& MusicAssets::getMusic(string name) {
		auto it = musicStreamers.find(name);

		if (it == musicStreamers.end()) {
			spdlog::error("[MusicAssets] music '" + name + "' was not registered");

			exit(1);
		}

		return *(it->second);
	}

}
