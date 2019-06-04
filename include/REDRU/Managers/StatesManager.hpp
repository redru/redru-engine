#pragma once
#include <memory>
#include <iostream>
#include <map>

#include <spdlog/spdlog.h>

#include "AudioManager.hpp"
#include "InputManager.hpp"
#include "GraphicsManager.hpp"
#include "REDRU/Components/State.hpp"

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

	public:

		StatesManager(RedruEngine& engine);

		void initialize();

		void update();

		void fixedUpdate();

		void registerState(string name, shared_ptr<State> state);

		void requestStateChange(string name);

		void nextState();

	public:

		bool hasActiveState();

		bool hasRequestedState();

	};

}
