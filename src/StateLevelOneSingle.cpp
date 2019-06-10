#include "StateLevelOneSingle.hpp"

namespace re {

	StateLevelOneSingle::StateLevelOneSingle(RedruEngine& engine) :
		engine(engine),
		gameObjects(12) {
	}

	void StateLevelOneSingle::onInit() {
		flippedCards = 0;
		mustWait = false;
		mustWaitTime = 0;
		firstFlippedCard = nullptr;
		secondFlippedCard = nullptr;

		background = make_unique<GenericGameObject>(GenericGameObject("BACKGROUND", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_TABLE")));

		sf::Texture& tex1 = engine.getTextureAssets()->loadTexture("TEX_CARD_1");
		sf::Texture& tex2 = engine.getTextureAssets()->loadTexture("TEX_CARD_2");
		sf::Texture& tex3 = engine.getTextureAssets()->loadTexture("TEX_CARD_3");
		sf::Texture& tex4 = engine.getTextureAssets()->loadTexture("TEX_CARD_4");

		sf::Texture& texFront1 = engine.getTextureAssets()->loadTexture("TEX_CARD_FRONT_1");
		sf::Texture& texFront2 = engine.getTextureAssets()->loadTexture("TEX_CARD_FRONT_2");
		sf::Texture& texFront3 = engine.getTextureAssets()->loadTexture("TEX_CARD_FRONT_3");
		sf::Texture& texFront4 = engine.getTextureAssets()->loadTexture("TEX_CARD_FRONT_4");
		sf::Texture& texFront5 = engine.getTextureAssets()->loadTexture("TEX_CARD_FRONT_5");
		sf::Texture& texFront6 = engine.getTextureAssets()->loadTexture("TEX_CARD_FRONT_6");

		gameObjects[0] = make_unique<CardObject>(CardObject("CARD_1", engine, texFront1, tex1, 1));
		gameObjects[1] = make_unique<CardObject>(CardObject("CARD_2", engine, texFront1, tex2, 1));
		gameObjects[2] = make_unique<CardObject>(CardObject("CARD_3", engine, texFront2, tex3, 2));
		gameObjects[3] = make_unique<CardObject>(CardObject("CARD_4", engine, texFront2, tex4, 2));
		gameObjects[4] = make_unique<CardObject>(CardObject("CARD_5", engine, texFront3, tex1, 3));
		gameObjects[5] = make_unique<CardObject>(CardObject("CARD_6", engine, texFront3, tex2, 3));
		gameObjects[6] = make_unique<CardObject>(CardObject("CARD_7", engine, texFront4, tex3, 4));
		gameObjects[7] = make_unique<CardObject>(CardObject("CARD_8", engine, texFront4, tex4, 4));
		gameObjects[8] = make_unique<CardObject>(CardObject("CARD_9", engine, texFront5, tex1, 5));
		gameObjects[9] = make_unique<CardObject>(CardObject("CARD_10", engine, texFront5, tex2, 5));
		gameObjects[10] = make_unique<CardObject>(CardObject("CARD_11", engine, texFront6, tex3, 6));
		gameObjects[11] = make_unique<CardObject>(CardObject("CARD_12", engine, texFront6, tex4, 6));

		unsigned seed = chrono::system_clock::now().time_since_epoch().count();

		shuffle(begin(gameObjects), end(gameObjects), default_random_engine(seed));

		const float x_OFFSET = 282.f;
		const float Y_OFFSET = 360.f;

		for (int i = 1, objCount = 0; i < 3; i++) {
			for (int e = 1; e < 7; e++, objCount++) {
				gameObjects[objCount]->setPosition(x_OFFSET * e, Y_OFFSET * i);
			}
		}
	}

	void StateLevelOneSingle::onClose() {
		firstFlippedCard = nullptr;
		secondFlippedCard = nullptr;

		for (GameObjects::iterator it = gameObjects.begin(); it != gameObjects.end(); it++) {
			it->release();
		}

		background.release();
	}

	void StateLevelOneSingle::update() {
		if (mustWait) {
			mustWaitTime += engine.getElpasedFromLast();

			if (mustWaitTime >= 1000) {
				firstFlippedCard->setFaceUp(false);
				secondFlippedCard->setFaceUp(false);

				firstFlippedCard = nullptr;
				secondFlippedCard = nullptr;

				mustWait = false;
				mustWaitTime = 0;
			}

			return;
		}

		if (firstFlippedCard != nullptr && secondFlippedCard != nullptr) {
			if (secondFlippedCard->getId() == firstFlippedCard->getId()) {
				firstFlippedCard = nullptr;
				return;
			}

			if (firstFlippedCard->getGroup() != secondFlippedCard->getGroup()) {
				mustWait = true;
				return;
			}

			firstFlippedCard->setLocked(true);
			secondFlippedCard->setLocked(true);

			flippedCards += 2;

			if (flippedCards == gameObjects.size()) {
				mustWait = true;
				return;
			}

			firstFlippedCard = nullptr;
			secondFlippedCard = nullptr;
		}

		if (flippedCards == gameObjects.size()) {
			engine.changeState("LEVEL_ONE_SINGLE");
		}
	}

	void StateLevelOneSingle::fixedUpdate() { }

	void StateLevelOneSingle::draw() {
		sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

		background->draw(window);

		for (GameObjects::iterator it = gameObjects.begin(); it != gameObjects.end(); it++) {
			(*it)->draw(window);
		}
	}

	void StateLevelOneSingle::onInput(sf::Event& event) {
		if (mustWait) {
			return;
		}

		if (event.type == sf::Event::KeyReleased) {
			switch (event.key.code) {
			case sf::Keyboard::Escape:
				engine.changeState("MAIN_MENU");
				break;
			}
		}

		for (GameObjects::iterator it = gameObjects.begin(); it < gameObjects.end(); it++) {
			(*it)->onInput(event);
		}
	}

	void StateLevelOneSingle::onEvent(GameEvent& event) {
		if (event.getType() == "CARD_FLIPPED") {
			// If event was CARD_FLIPPED, we understand we can safely cast to child CardObject
			CardObject* object = dynamic_cast<CardObject*>(event.getSource());
			
			// If first selection
			if (firstFlippedCard == nullptr) {
				firstFlippedCard = object;
			} else {
				secondFlippedCard = object;
			}
		}
	}

}
