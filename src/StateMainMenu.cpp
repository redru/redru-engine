#include "StateMainMenu.hpp"

StateMainMenu::StateMainMenu(re::RedruEngine& engine) :
	engine(engine),
	mainMenuImage(),
	onePlayerButton(),
	onePlayerVsAiButton(),
	exitButton() {
}

void StateMainMenu::onInit(shared_ptr<re::StateInitializationData> data) {
	engine.getAudioManager()->stopMusic();

	sf::Font& uiFont = engine.getFontAssets()->getFont("UI_FONT");

	mainMenuImage.reset(new re::GenericGameObject("BACKGROUND", engine, engine.getTextureAssets()->loadTexture("TEX_MAIN_MENU")));

	onePlayerButton.reset(new re::GenericButtonObject("ONE_PLAYER_B", engine));
	onePlayerButton->setPosition(200.f, 180.f);
	onePlayerButton->setColor(0, 0, 255, 255);
	onePlayerButton->setSize(230.f, 60.f);
	onePlayerButton->setFont(uiFont);
	onePlayerButton->setFontSize(36);
	onePlayerButton->setText("1 Player");

	onePlayerVsAiButton.reset(new re::GenericButtonObject("ONE_PLAYER_AI_B", engine));
	onePlayerVsAiButton->setPosition(200.f, 280.f);
	onePlayerVsAiButton->setColor(0, 0, 255, 255);
	onePlayerVsAiButton->setSize(230.f, 60.f);
	onePlayerVsAiButton->setFont(uiFont);
	onePlayerVsAiButton->setFontSize(36);
	onePlayerVsAiButton->setText("1 Player VS AI");

	twoPlayersButton.reset(new re::GenericButtonObject("TWO_PLAYERS_B", engine));
	twoPlayersButton->setPosition(200.f, 380.f);
	twoPlayersButton->setColor(0, 0, 255, 255);
	twoPlayersButton->setSize(230.f, 60.f);
	twoPlayersButton->setFont(uiFont);
	twoPlayersButton->setFontSize(36);
	twoPlayersButton->setText("2 Players");

	exitButton.reset(new re::GenericButtonObject("EXIT_B", engine));
	exitButton->setPosition(200.f, 480.f);
	exitButton->setColor(0, 0, 255, 255);
	exitButton->setSize(230.f, 60.f);
	exitButton->setFont(uiFont);
	exitButton->setFontSize(36);
	exitButton->setText("Exit");
}

void StateMainMenu::onClose() {
	mainMenuImage.release();
	onePlayerButton.release();
	exitButton.release();
}

void StateMainMenu::reset() { }

void StateMainMenu::update() { }

void StateMainMenu::fixedUpdate() { }

void StateMainMenu::draw() {
	sf::RenderWindow& window = engine.getGraphicsManager()->getWindow();

	mainMenuImage->draw(window);
	onePlayerButton->draw(window);
	onePlayerVsAiButton->draw(window);
	twoPlayersButton->draw(window);
	exitButton->draw(window);
}

void StateMainMenu::onInput(sf::Event& event) {
	if (event.type == sf::Event::KeyReleased) {
		switch (event.key.code) {
		case sf::Keyboard::Escape:
			engine.stop();
			break;

		/* case sf::Keyboard::Enter:
			LevelOneData* data = new LevelOneData();
			data->setPlayerNames(vector<string>{ "RedrU", "AI" });

			engine.changeState("LEVEL_ONE", false, data);
			break; */
		}
	} else if (event.type == sf::Event::MouseButtonPressed) {
		if (onePlayerButton->getBoundingBox().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
			PlayerStatus* player1 = new PlayerStatus();
			player1->name = "Player";
			player1->points = 0;
			player1->ai = false;

			engine.changeState("LEVEL_ONE", false, new LevelOneData(vector<PlayerStatus*>{ player1 }, false));
		} else if (onePlayerVsAiButton->getBoundingBox().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
			PlayerStatus* player1 = new PlayerStatus();
			player1->name = "Player";
			player1->points = 0;
			player1->ai = false;

			PlayerStatus* player2 = new PlayerStatus();
			player2->name = "AI";
			player2->points = 0;
			player2->ai = true;

			engine.changeState("LEVEL_ONE", false, new LevelOneData(vector<PlayerStatus*>{ player1, player2 }, true));
		} else if (twoPlayersButton->getBoundingBox().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
			PlayerStatus* player1 = new PlayerStatus();
			player1->name = "Player 1";
			player1->points = 0;
			player1->ai = false;

			PlayerStatus* player2 = new PlayerStatus();
			player2->name = "Player 2";
			player2->points = 0;
			player2->ai = false;

			engine.changeState("LEVEL_ONE", false, new LevelOneData(vector<PlayerStatus*>{ player1, player2 }, true));
		} else if (exitButton->getBoundingBox().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
			engine.stop();
		}
	}
}

void StateMainMenu::onEvent(re::GameEvent& event) {

}
