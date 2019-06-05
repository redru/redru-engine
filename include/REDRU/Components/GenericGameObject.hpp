#pragma once
#include <memory>

#include <SFML/Graphics.hpp>

#include "REDRU/Components/GameObject.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	using namespace std;

	class GenericGameObject : public GameObject {

	private:

		RedruEngine& engine;

		sf::Sprite sprite;

	public:

		GenericGameObject(RedruEngine& engine, sf::Texture& texture);

		void update() override;

		void fixedUpdate() override;

		void draw(sf::RenderWindow& window) override;

		void onInput(sf::Event event) override;

		sf::FloatRect getBoundingBox() override;

		void setPosition(float x, float y) override;

		void setColor(int r, int g, int b, int a) override;

	};

}
