#pragma once
#include <SFML/Graphics.hpp>

#include "REDRU/Components/State.hpp"
#include "REDRU/RedruEngine.hpp"
#include "Button.hpp"

namespace re {

	class StateMainMenu : public State {

	private:

		RedruEngine& engine;

		unique_ptr<sf::Sprite> mainMenuImage;

		unique_ptr<Button> startButton;

	public:

		StateMainMenu(RedruEngine& engine);

		void onInit() override;

		void onClose() override;

		void update() override;

		void fixedUpdate() override;

		void draw() override;

	};

}
