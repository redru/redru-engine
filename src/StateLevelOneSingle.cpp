#include "StateLevelOneSingle.hpp"

namespace re {

	StateLevelOneSingle::StateLevelOneSingle(RedruEngine& engine) :
		engine(engine),
		gameObjects(12) {
	}

	void StateLevelOneSingle::onInit() {
		background = make_unique<GenericGameObject>(GenericGameObject("BACKGROUND", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_TABLE")));

		gameObjects[0] = make_unique<CardObject>(CardObject("CARD_1_1", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_1"), engine.getTextureAssets()->loadTexture("TEX_CARD_1")));
		gameObjects[1] = make_unique<CardObject>(CardObject("CARD_2_1", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_2"), engine.getTextureAssets()->loadTexture("TEX_CARD_2")));
		gameObjects[2] = make_unique<CardObject>(CardObject("CARD_3_1", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_3"), engine.getTextureAssets()->loadTexture("TEX_CARD_3")));
		gameObjects[3] = make_unique<CardObject>(CardObject("CARD_4_1", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_4"), engine.getTextureAssets()->loadTexture("TEX_CARD_4")));
		gameObjects[4] = make_unique<CardObject>(CardObject("CARD_1_2", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_1"), engine.getTextureAssets()->loadTexture("TEX_CARD_1")));
		gameObjects[5] = make_unique<CardObject>(CardObject("CARD_2_2", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_2"), engine.getTextureAssets()->loadTexture("TEX_CARD_2")));
		gameObjects[6] = make_unique<CardObject>(CardObject("CARD_3_2", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_3"), engine.getTextureAssets()->loadTexture("TEX_CARD_3")));
		gameObjects[7] = make_unique<CardObject>(CardObject("CARD_4_2", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_4"), engine.getTextureAssets()->loadTexture("TEX_CARD_4")));
		gameObjects[8] = make_unique<CardObject>(CardObject("CARD_1_3", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_1"), engine.getTextureAssets()->loadTexture("TEX_CARD_1")));
		gameObjects[9] = make_unique<CardObject>(CardObject("CARD_2_3", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_2"), engine.getTextureAssets()->loadTexture("TEX_CARD_2")));
		gameObjects[10] = make_unique<CardObject>(CardObject("CARD_3_3", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_3"), engine.getTextureAssets()->loadTexture("TEX_CARD_3")));
		gameObjects[11] = make_unique<CardObject>(CardObject("CARD_4_3", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_4"), engine.getTextureAssets()->loadTexture("TEX_CARD_4")));
	
		gameObjects[0]->setPosition(20.f, 150.f);
		gameObjects[1]->setPosition(190.f, 150.f);
		gameObjects[2]->setPosition(360.f, 150.f);
		gameObjects[3]->setPosition(530.f, 150.f);
		gameObjects[4]->setPosition(700.f, 150.f);
		gameObjects[5]->setPosition(870.f, 150.f);
		gameObjects[6]->setPosition(20.f, 420.f);
		gameObjects[7]->setPosition(190.f, 420.f);
		gameObjects[8]->setPosition(360.f, 420.f);
		gameObjects[9]->setPosition(530.f, 420.f);
		gameObjects[10]->setPosition(700.f, 420.f);
		gameObjects[11]->setPosition(870.f, 420.f);
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
