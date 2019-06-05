#include "REDRU/Managers/EventsManager.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	////////////////////////////////////////////////////
	// Game Event class
	////////////////////////////////////////////////////
	GameEvent::GameEvent(string type) : type(type), source() { }

	void GameEvent::setSource(GameObject& source) {
		this->source = &source;
	}

	GameObject& GameEvent::getSource() {
		return *source;
	}

	void GameEvent::setType(string type) {
		this->type = type;
	}

	string GameEvent::getType() {
		return type;
	}

	////////////////////////////////////////////////////
	// Events Manager class
	////////////////////////////////////////////////////
	EventsManager::EventsManager(RedruEngine& engine) : engine(engine) {
		spdlog::debug("[EventsManager] -- created --");
	}

	void EventsManager::initialize() {
		spdlog::debug("[EventsManager] -- initialized --");
	}

	void EventsManager::sendEvent(GameEvent& event) {
		engine.sendEvent(event);
	}

}
