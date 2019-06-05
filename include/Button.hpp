#pragma once
#include <string>

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include "REDRU/Components/GameObject.hpp"

namespace re {

	using namespace std;

	class Button : public GameObject {

	private:

		sf::Sprite sprite;

		sf::Text textElement;

		sf::Font font;
		
	public:

		Button(sf::Texture& texture, string text);

		void update() override;

		void fixedUpdate() override;

		void draw(sf::RenderWindow& window) override;

		void setPosition(float x, float y) override;

	};

}
