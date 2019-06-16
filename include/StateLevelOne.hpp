#pragma once
#include <algorithm>
#include <chrono>
#include <map>
#include <random>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include "REDRU/Components/GenericGameObject.hpp"
#include "REDRU/Components/State.hpp"
#include "REDRU/Data/StateInitializationData.hpp"
#include "REDRU/RedruEngine.hpp"
#include "CardObject.hpp"
#include "LevelOneData.hpp"
#include "LevelOneInterface.hpp"
#include "StateStatus.hpp"

typedef vector<unique_ptr<re::GameObject>> GameObjects;

class StateLevelOne : public re::State {

private:

	re::RedruEngine& engine;

	LevelOneInterface ui;

	shared_ptr<StateStatus> status;

	unique_ptr<re::GameObject> background;

	GameObjects gameObjects;

	CardObject* firstFlippedCard;

	CardObject* secondFlippedCard;

	/////////////////////////////////////////
	// AI
	/////////////////////////////////////////
	int aiCounter;

	vector<CardObject*> aiMemory;

	/////////////////////////////////////////
	// Game Dev
	/////////////////////////////////////////
	int currentSelected;

	int flippedCards;

	bool mustWait;

	int mustWaitTime;

public:

	StateLevelOne(re::RedruEngine& engine);

	/////////////////////////////////////////
	// State Overrides
	/////////////////////////////////////////
	void onInit(shared_ptr<re::StateInitializationData> data) override;

	void onClose() override;

	void reset() override;

	void update() override;

	void fixedUpdate() override;

	void draw() override;

	void onInput(sf::Event& event) override;

	void onEvent(re::GameEvent& event) override;

private:

	//////////////////////////////////////////
	// Private functions
	//////////////////////////////////////////
	void executeAI();

	void shuffleCards(GameObjects& cards);

	void locateStandardPosition(GameObjects& cards);

};
