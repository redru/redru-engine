#pragma once
#include <memory>
#include <string>

#include <spdlog/spdlog.h>

#include "REDRU/Components/GameObject.hpp"

namespace re {

	using namespace std;

	class RedruEngine;

	////////////////////////////////////////////////////
	// Game Event class
	////////////////////////////////////////////////////
	class GameEvent {

	private:

		string type;

		GameObject* source;

	public:

		GameEvent(string type = "DEFAULT");

		void setSource(GameObject& source);

		GameObject& getSource();

		void setType(string type);

		string getType();

	};

	////////////////////////////////////////////////////
	// Events Manager class
	////////////////////////////////////////////////////
	class EventsManager {

	private:

		RedruEngine& engine;

	public:

		EventsManager(RedruEngine& engine);

		void initialize();

		void sendEvent(GameEvent& event);

	};

}
