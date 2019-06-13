#include "REDRU/Assets/FontAssets.hpp"

namespace re {

	FontAssets::FontAssets(RedruEngine& engine) : engine(engine), fonts() {
		spdlog::debug("[FontAssets] -- created --");
	}

	void FontAssets::initialize() {
		spdlog::debug("[FontAssets] -- initialized --");
	}

	void FontAssets::registerAsset(string name, string file) {
		sf::Font* font = new sf::Font();

		if (!font->loadFromFile(file)) {
			spdlog::error("[FontAssets] font '" + name + "' loading error");

			exit(1);
		}

		fonts[name] = unique_ptr<sf::Font>(font);

		spdlog::debug("[FontAssets] registered font '" + name + "' to file '" + file + "'");
	}

	sf::Font& FontAssets::getFont(string name) {
		auto it = fonts.find(name);

		if (it == fonts.end()) {
			spdlog::error("[FontAssets] font '" + name + "' was not registered");

			exit(1);
		}

		return *(it->second);
	}

}
