#include "REDRU/Managers/GraphicsManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	GraphicsManager::GraphicsManager(RedruEngine& engine) : engine(engine) {
	}

	void GraphicsManager::initialize() {
		window.reset(new sf::RenderWindow(sf::VideoMode(960, 540), "Redru Engine - 960 x 540"));
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

	void GraphicsManager::draw() {
		window->clear();

		window->display();
	}

}
