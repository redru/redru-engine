#include "StateLevelOne.hpp"

StateLevelOne::StateLevelOne(re::RedruEngine& engine) :
	engine(engine),
	status(new StateStatus(vector<string>{ "RedrU", "AI" })),
	ui(engine),
	gameObjects(12),
	flippedCards(0),
	mustWait(false),
	mustWaitTime(0),
	currentSelected(0),
	firstFlippedCard(nullptr),
	secondFlippedCard(nullptr) {

	ui.setStatus(status);
	ui.initialize();
}

void StateLevelOne::onInit() {
	// Music
	engine.getAudioManager()->playMusic("BACKGROUND");

	// Load resources
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

	// Initialize Game Objects
	background = make_unique<re::GenericGameObject>(re::GenericGameObject("BACKGROUND", engine, engine.getTextureAssets()->loadTexture("TEX_CARD_TABLE")));

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

	reset();
}

void StateLevelOne::onClose() {
	firstFlippedCard = nullptr;
	secondFlippedCard = nullptr;

	for (GameObjects::iterator it = gameObjects.begin(); it != gameObjects.end(); it++) {
		it->release();
	}

	background.release();
}

void StateLevelOne::reset() {
	// State members initialization
	flippedCards = 0;
	mustWait = false;
	mustWaitTime = 0;
	currentSelected = 0;
	firstFlippedCard = nullptr;
	secondFlippedCard = nullptr;

	status->nextPlayer();

	for (auto it = gameObjects.begin(); it != gameObjects.end(); it++) {
		dynamic_cast<CardObject*>((*it).get())->reset();
	}

	// Shuffle
	shuffleCards(gameObjects);

	dynamic_cast<CardObject*>(gameObjects[currentSelected].get())->setSelected(true);

	// Cards positioning
	locateStandardPosition(gameObjects);
}

void StateLevelOne::update() {
	ui.update();

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
		// Card was the same, so it returned down
		if (*secondFlippedCard == *firstFlippedCard) {
			firstFlippedCard = nullptr;
			return;
		}

		// If flipped cards are different
		if (firstFlippedCard->getGroup() != secondFlippedCard->getGroup()) {
			// Start wait time
			mustWait = true;

			// Change player
			status->nextPlayer();

			return;
		}

		firstFlippedCard->setLocked(true);
		secondFlippedCard->setLocked(true);

		engine.getAudioManager()->playSound("CARD_MATCH");

		flippedCards += 2;

		// Add points to the current player
		status->addPoints(1);

		if (flippedCards == gameObjects.size()) {
			mustWait = true;
			return;
		}

		firstFlippedCard = nullptr;
		secondFlippedCard = nullptr;
	}

	if (flippedCards == gameObjects.size()) {
		reset();
	}
}

void StateLevelOne::fixedUpdate() { }

void StateLevelOne::draw() {
	sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

	// Draw background
	background->draw(window);

	// Draw cards
	for (GameObjects::iterator it = gameObjects.begin(); it != gameObjects.end(); it++) {
		(*it)->draw(window);
	}

	// Draw user interface
	ui.draw();
}

void StateLevelOne::onInput(sf::Event& event) {
	if (event.type == sf::Event::KeyReleased) {
		re::GameEvent gameEvent("CARD_FLIPPED");
		CardObject* tmp;

		switch (event.key.code) {
		case sf::Keyboard::Left:
			dynamic_cast<CardObject*>(gameObjects[currentSelected].get())->setSelected(false);

			if (currentSelected - 1 < 0) currentSelected = gameObjects.size() - 1;
			else currentSelected--;

			dynamic_cast<CardObject*>(gameObjects[currentSelected].get())->setSelected(true);
			break;
		case sf::Keyboard::Up:
			dynamic_cast<CardObject*>(gameObjects[currentSelected].get())->setSelected(false);

			if (currentSelected - 6 < 0) currentSelected += 6;
			else currentSelected -= 6;

			dynamic_cast<CardObject*>(gameObjects[currentSelected].get())->setSelected(true);
			break;
		case sf::Keyboard::Right:
			dynamic_cast<CardObject*>(gameObjects[currentSelected].get())->setSelected(false);

			if (currentSelected + 1 >= gameObjects.size()) currentSelected = 0;
			else currentSelected++;

			dynamic_cast<CardObject*>(gameObjects[currentSelected].get())->setSelected(true);
			break;
		case sf::Keyboard::Down:
			dynamic_cast<CardObject*>(gameObjects[currentSelected].get())->setSelected(false);

			if (currentSelected + 6 >= gameObjects.size()) currentSelected -= 6;
			else currentSelected += 6;

			dynamic_cast<CardObject*>(gameObjects[currentSelected].get())->setSelected(true);
			break;
		case sf::Keyboard::Enter:
			tmp = dynamic_cast<CardObject*>(gameObjects[currentSelected].get());

			if (tmp->isLocked() || tmp->isFaceUp() || mustWait) {
				break;
			}

			tmp->flip();

			gameEvent.setSource(tmp);

			engine.getEventsManager()->sendEvent(gameEvent);
			break;
		case sf::Keyboard::Escape:
			engine.changeState("MAIN_MENU");
			break;
		}
	}

	if (mustWait) {
		return;
	}

	for (GameObjects::iterator it = gameObjects.begin(); it < gameObjects.end(); it++) {
		(*it)->onInput(event);
	}
}

void StateLevelOne::onEvent(re::GameEvent& event) {
	if (event.getType() == "CARD_FLIPPED") {
		// If event was CARD_FLIPPED, we understand we can safely cast to child CardObject
		CardObject* object = dynamic_cast<CardObject*>(event.getSource());

		// If first selection
		if (firstFlippedCard == nullptr) {
			firstFlippedCard = object;
		}
		else {
			secondFlippedCard = object;
		}
	}
}

void StateLevelOne::shuffleCards(GameObjects& cards) {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	shuffle(begin(cards), end(cards), default_random_engine(seed));
}

void StateLevelOne::locateStandardPosition(GameObjects& cards) {
	const float x_OFFSET = 282.f;
	const float Y_OFFSET = 360.f;

	for (int i = 1, objCount = 0; i < 3; i++) {
		for (int e = 1; e <= 6; e++, objCount++) {
			cards[objCount]->setPosition(x_OFFSET * e, Y_OFFSET * i);
		}
	}
}
