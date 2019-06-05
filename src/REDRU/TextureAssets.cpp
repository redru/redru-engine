#include "REDRU/Assets/TextureAssets.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	TextureAssets::TextureAssets(RedruEngine& engine) : engine(engine), texturesMapping(), loadedTextures(){
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
		auto it = texturesMapping.find(name);

		if (it == texturesMapping.end()) {
			spdlog::error("[TexturesAsset] texture '" + name + "' was not registered");

			exit(1);
		}

		// Load from cache if present
		auto it2 = loadedTextures.find(name);

		if (it2 != loadedTextures.end()) {
			spdlog::debug("[TexturesAsset] texture '" + name + "' was loaded from cache");

			return *(it2->second);
		}

		sf::Texture* texture = new sf::Texture();

		if (!texture->loadFromFile(it->second)) {
			spdlog::error("[TexturesAsset] texture '" + name + "' was found");

			exit(1);
		}

		// Put in cache
		loadedTextures[name] = make_unique<sf::Texture>(*texture);

		return *texture;
	}

	void TextureAssets::clearCache() {
		loadedTextures.clear();

		spdlog::debug("[TextureAssets] textures cache was cleared");
	}

}
