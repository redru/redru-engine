#pragma once
#include <SFML/Graphics.hpp>

#include "LevelOneData.hpp"
#include "REDRU/Components/GenericGameObject.hpp"
#include "REDRU/Components/GenericButtonObject.hpp"
#include "REDRU/Components/State.hpp"
#include "REDRU/Data/StateInitializationData.hpp"
#include "REDRU/RedruEngine.hpp"
#include "StateStatus.hpp"

using namespace std;

class StateMainMenu : public re::State {

private:

	re::RedruEngine& engine;

	unique_ptr<re::GameObject> mainMenuImage;

	unique_ptr<re::GenericButtonObject> onePlayerButton;

	unique_ptr<re::GenericButtonObject> onePlayerVsAiButton;

	unique_ptr<re::GenericButtonObject> twoPlayersButton;

	unique_ptr<re::GenericButtonObject> exitButton;

public:

	StateMainMenu(re::RedruEngine& engine);

	void onInit(shared_ptr<re::StateInitializationData> data) override;

	void onClose() override;

	void reset() override;

	void update() override;

	void fixedUpdate() override;

	void draw() override;

	void onInput(sf::Event& event) override;

	void onEvent(re::GameEvent& event) override;

};
