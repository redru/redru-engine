#pragma once
#include <memory>

#include <SFML/Graphics.hpp>

#include "REDRU/RedruEngine.hpp"
#include "REDRU/Components/GameObject.hpp"

namespace re {

	class SplashImageObject : public GameObject {

	private:

		RedruEngine& engine;

		sf::Sprite sprite;

	public:

		SplashImageObject(RedruEngine& engine, sf::Texture& texture);

		void update() override;

		void fixedUpdate() override;

		void draw(sf::RenderWindow& window) override;

		void setPosition(float x, float y) override;

		void setColor(int r, int g, int b, int a) override;

	};

}
