#pragma once
#include <SFML/Graphics.hpp>

#include "REDRU/Managers/EventsManager.hpp"

namespace re {

	class State {

	public:

		virtual void onInit() = 0;

		virtual void onClose() = 0;

		virtual void reset() = 0;

		virtual void update() = 0;

		virtual void fixedUpdate() = 0;

		virtual void draw() = 0;

		virtual void onInput(sf::Event& event) = 0;

		virtual void onEvent(GameEvent& event) = 0;

	};

}
