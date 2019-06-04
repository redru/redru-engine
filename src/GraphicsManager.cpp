#include "REDRU/Managers/GraphicsManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	GraphicsManager::GraphicsManager(RedruEngine& engine) : engine(engine) {
		textureAssets.reset(new TextureAssets());
		cout << "[GraphicsManager] => linked 'TextureAssets'" << endl;

		cout << "[GraphicsManager] -- created --" << endl;
	}

	void GraphicsManager::initialize() {
		window.reset(new sf::RenderWindow(sf::VideoMode(960, 540), "Redru Engine - 960 x 540"));

		textureAssets->initialize();

		cout << "[GraphicsManager] -- initialized --" << endl;
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
