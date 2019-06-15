#pragma once
#include <memory>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include "REDRU/Components/GenericGameObject.hpp"
#include "REDRU/Components/State.hpp"
#include "REDRU/RedruEngine.hpp"
#include "CardObject.hpp"
#include "LevelOneInterface.hpp"
#include "StateStatus.hpp"

namespace re {

	typedef vector<unique_ptr<GameObject>> GameObjects;

	class StateLevelOne : public State {

	private:

		RedruEngine& engine;

		LevelOneInterface ui;

		shared_ptr<StateStatus> status;

		unique_ptr<GameObject> background;

		GameObjects gameObjects;

		CardObject* firstFlippedCard;

		CardObject* secondFlippedCard;

		int currentSelected;

		int flippedCards;

		bool mustWait;

		int mustWaitTime;

	public:

		StateLevelOne(RedruEngine& engine);

		/////////////////////////////////////////
		// State Overrides
		/////////////////////////////////////////
		void onInit() override;

		void onClose() override;

		void reset() override;

		void update() override;

		void fixedUpdate() override;

		void draw() override;

		void onInput(sf::Event& event) override;

		void onEvent(GameEvent& event) override;

	private:

		//////////////////////////////////////////
		// Private functions
		//////////////////////////////////////////
		void shuffleCards(GameObjects& cards);

		void locateStandardPosition(GameObjects& cards);

	};

}
