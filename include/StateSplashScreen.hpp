#pragma once
#include <memory>

#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

#include "REDRU/Components/State.hpp"
#include "REDRU/RedruEngine.hpp"

#include "SplashImageObject.hpp"

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

	};

}
