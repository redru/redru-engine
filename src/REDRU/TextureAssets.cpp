#include "REDRU/Assets/TextureAssets.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	TextureAssets::TextureAssets(RedruEngine& engine) : engine(engine), texturesMapping() {
		spdlog::debug("[TextureAssets] -- created --");
	}

	void TextureAssets::initialize() {
		spdlog::debug("[TextureAssets] -- initialized --");
	}

	void TextureAssets::registerAsset(string name, string file) {
		texturesMapping[name] = file;

		spdlog::debug("[TextureAssets] registered texture '" + name + "' to file '" + file + "'");
	}

	sf::Texture& TextureAssets::loadTexture(string name) {
		sf::Texture* texture = new sf::Texture();

		auto it = texturesMapping.find(name);

		if (it == texturesMapping.end()) {
			spdlog::error("[TexturesAsset] texture '" + name + "' was not registered");

			exit(1);
		}

		if (!texture->loadFromFile(it->second)) {
			spdlog::error("[TexturesAsset] texture '" + name + "' was found");

			exit(1);
		}

		return *texture;
	}

}
