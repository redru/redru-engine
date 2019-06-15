#pragma once
#include <memory>
#include <iostream>
#include <map>

#include <spdlog/spdlog.h>

#include "REDRU/Components/State.hpp"
#include "REDRU/Data/StateInitializationData.hpp"
#include "REDRU/Managers/AudioManager.hpp"
#include "REDRU/Managers/EventsManager.hpp"
#include "REDRU/Managers/InputManager.hpp"
#include "REDRU/Managers/GraphicsManager.hpp"

namespace re {

	using namespace std;

	class RedruEngine;

	typedef map<string, shared_ptr<State>> States;

	class StatesManager {

	private:

		RedruEngine& engine;

		shared_ptr<AudioManager> audioManager;

		shared_ptr<InputManager> inputManager;

		shared_ptr<GraphicsManager> graphicsManager;

		States states;

		shared_ptr<State> activeState;

		shared_ptr<State> requestedState;

		shared_ptr<StateInitializationData> stateInitializationData;

	public:

		StatesManager(RedruEngine& engine);

		void initialize();

		void update();

		void fixedUpdate();

		void registerState(string name, State* state);

		void requestStateChange(string name, StateInitializationData* data = nullptr);

		void nextState();

		void onEvent(GameEvent& event);

	public:

		bool hasActiveState();

		bool hasRequestedState();

	};

}
