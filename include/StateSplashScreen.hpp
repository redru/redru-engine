#pragma once
#include <math.h>
#include <memory>

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include "REDRU/Components/State.hpp"
#include "REDRU/Components/GenericGameObject.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	class StateSplashScreen : public State {

	private:

		RedruEngine& engine;

		unique_ptr<GameObject> splashImage;

		sf::Clock clock;

	public:

		StateSplashScreen(RedruEngine& engine);

		void onInit() override;

		void onClose() override;

		void update() override;

		void fixedUpdate() override;

		void draw() override;

		void onInput(sf::Event& event) override;

		void onEvent(GameEvent& event) override;

	};

}
