#pragma once
#include <SFML/Graphics.hpp>

namespace re {

	class GameObject {

	public:

		virtual void update() = 0;

		virtual void fixedUpdate() = 0;

		virtual void draw(sf::RenderWindow& window) = 0;

		virtual void setPosition(float x, float y) = 0;

		virtual void setColor(int r, int g, int b, int a) = 0;

	};

}
