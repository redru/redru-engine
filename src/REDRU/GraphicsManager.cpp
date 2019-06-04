#include "REDRU/Managers/GraphicsManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	GraphicsManager::GraphicsManager(RedruEngine& engine) : engine(engine) {
		textureAssets.reset(new TextureAssets());
		spdlog::debug("[GraphicsManager] => linked 'TextureAssets'");

		spdlog::debug("[GraphicsManager] -- created --");
	}

	void GraphicsManager::initialize() {
		window.reset(new sf::RenderWindow(sf::VideoMode(960, 540), "Redru Engine - 960 x 540"));

		textureAssets->initialize();

		textureAssets->registerAsset("SPLASH_IMAGE", "resources/splash_image.png");

		spdlog::debug("[GraphicsManager] -- initialized --");
	}

	bool GraphicsManager::isWindowOpen() {
		return window->isOpen();
	}

	bool GraphicsManager::nextEvent(sf::Event& event) {
		return window->pollEvent(event);
	}

	void GraphicsManager::closeWindow() {
		window->close();
	}

	sf::RenderWindow& GraphicsManager::getWindow() {
		return *window;
	}

}
