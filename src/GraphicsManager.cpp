#include "REDRU/Managers/GraphicsManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	GraphicsManager::GraphicsManager(RedruEngine& engine) : engine(engine) {
		cout << "[GraphicsManager]:" << endl;
		textureAssets.reset(new TextureAssets());
		cout << "  |- linked 'TextureAssets'" << endl;
		cout << "[GraphicsManager] created" << endl;
	}

	void GraphicsManager::initialize() {
		window.reset(new sf::RenderWindow(sf::VideoMode(960, 540), "Redru Engine - 960 x 540"));
		cout << "[GraphicsManager] initialized" << endl;
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
