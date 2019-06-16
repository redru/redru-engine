#pragma once
#include <string>

#include <SFML/Graphics.hpp>

#include "REDRU/Components/GameObject.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	using namespace std;

	class GenericButtonObject : public GameObject {

	private:

		RedruEngine& engine;

		sf::Text buttonText;

		sf::RectangleShape background;

	public:

		//////////////////////////////////////////////////////////////
		// Constructor
		//////////////////////////////////////////////////////////////

		GenericButtonObject(string id, RedruEngine& engine);

		//////////////////////////////////////////////////////////////
		// GameObject
		//////////////////////////////////////////////////////////////
		void update() override;

		void fixedUpdate() override;

		void draw(sf::RenderWindow& window) override;

		void onInput(sf::Event& event) override;

		void onEvent(re::GameEvent& event) override;

		sf::FloatRect getBoundingBox() override;

		void setPosition(float x, float y) override;

		void setSize(float x, float y) override;

		void setColor(int r, int g, int b, int a) override;

		//////////////////////////////////////////////////////////////
		// GenericButtonObject
		//////////////////////////////////////////////////////////////
		void setText(string text);

		void setFontSize(int size);

		void setFont(sf::Font& font);

	};

}
