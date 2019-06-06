#include "StateLevelOneSingle.hpp"

namespace re {

	StateLevelOneSingle::StateLevelOneSingle(RedruEngine& engine) :
		engine(engine),
		gameObjects(12) {
	}

	void StateLevelOneSingle::onInit() {
		background = make_unique<GenericGameObject>(GenericGameObject("BACKGROUND", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_TABLE")));

		sf::Texture& tex1 = engine.getTextureAssets()->loadTexture("TEX_CARD_1");
		sf::Texture& tex2 = engine.getTextureAssets()->loadTexture("TEX_CARD_2");
		sf::Texture& tex3 = engine.getTextureAssets()->loadTexture("TEX_CARD_3");
		sf::Texture& tex4 = engine.getTextureAssets()->loadTexture("TEX_CARD_4");

		gameObjects[0] = make_unique<CardObject>(CardObject("CARD_1", engine, tex1, tex1, 1));
		gameObjects[1] = make_unique<CardObject>(CardObject("CARD_2", engine, tex2, tex2, 1));
		gameObjects[2] = make_unique<CardObject>(CardObject("CARD_3", engine, tex3, tex3, 2));
		gameObjects[3] = make_unique<CardObject>(CardObject("CARD_4", engine, tex4, tex4, 2));
		gameObjects[4] = make_unique<CardObject>(CardObject("CARD_5", engine, tex1, tex1, 3));
		gameObjects[5] = make_unique<CardObject>(CardObject("CARD_6", engine, tex2, tex2, 3));
		gameObjects[6] = make_unique<CardObject>(CardObject("CARD_7", engine, tex3, tex3, 4));
		gameObjects[7] = make_unique<CardObject>(CardObject("CARD_8", engine, tex4, tex4, 4));
		gameObjects[8] = make_unique<CardObject>(CardObject("CARD_9", engine, tex1, tex1, 5));
		gameObjects[9] = make_unique<CardObject>(CardObject("CARD_10", engine, tex2, tex2, 5));
		gameObjects[10] = make_unique<CardObject>(CardObject("CARD_11", engine, tex3, tex3, 6));
		gameObjects[11] = make_unique<CardObject>(CardObject("CARD_12", engine, tex4, tex4, 6));
	
		gameObjects[0]->setPosition(282.f, 360.f);
		gameObjects[1]->setPosition(564.f, 360.f);
		gameObjects[2]->setPosition(846.f, 360.f);
		gameObjects[3]->setPosition(1128.f, 360.f);
		gameObjects[4]->setPosition(1410.f, 360.f);
		gameObjects[5]->setPosition(1692.f, 360.f);
		gameObjects[6]->setPosition(282.f, 720.f);
		gameObjects[7]->setPosition(564.f, 720.f);
		gameObjects[8]->setPosition(846.f, 720.f);
		gameObjects[9]->setPosition(1128.f, 720.f);
		gameObjects[10]->setPosition(1410.f, 720.f);
		gameObjects[11]->setPosition(1692.f, 720.f);
	}

	void StateLevelOneSingle::onClose() {
		background.release();
	}

	void StateLevelOneSingle::update() { }

	void StateLevelOneSingle::fixedUpdate() { }

	void StateLevelOneSingle::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		background->draw(window);

		for (GameObjects::iterator it = gameObjects.begin(); it != gameObjects.end(); it++) {
			(*it)->draw(window);
		}
	}

	void StateLevelOneSingle::onInput(sf::Event& event) {
		if (event.type == sf::Event::KeyReleased) {
			switch (event.key.code) {
			case sf::Keyboard::Escape:
				engine.changeState("MAIN_MENU");
				break;
			}
		}
	}

	void StateLevelOneSingle::onEvent(GameEvent& event) {
	}

}
