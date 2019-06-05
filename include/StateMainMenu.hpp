#pragma once
#include <SFML/Graphics.hpp>

#include "REDRU/Components/GenericGameObject.hpp"
#include "REDRU/Components/State.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	class StateMainMenu : public State {

	private:

		RedruEngine& engine;

		unique_ptr<GameObject> mainMenuImage;

		unique_ptr<GameObject> startButton;

		unique_ptr<GameObject> exitButton;

	public:

		StateMainMenu(RedruEngine& engine);

		void onInit() override;

		void onClose() override;

		void update() override;

		void fixedUpdate() override;

		void draw() override;

		void onInput(sf::Event& event) override;

		void onEvent() override;

	};

}
