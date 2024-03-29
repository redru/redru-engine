#include "REDRU/Managers/GraphicsManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	GraphicsManager::GraphicsManager(RedruEngine& engine) : engine(engine) {
		spdlog::debug("[GraphicsManager] -- created --");
	}

	void GraphicsManager::initialize() {
		window.reset(new sf::RenderWindow(sf::VideoMode(1920, 1080), "Redru Engine - 1920 x 1080"));

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
