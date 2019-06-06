#pragma once
#include <string>

#include <SFML/Graphics.hpp>

namespace re {

	using namespace std;

	class GameEvent;

	class GameObject {

	protected:

		string id;

	public:

		GameObject(string id) : id(id) { }

		void setId(string id) { this->id = id; }

		string& getId() { return id; }

		///////////////////////////////////////////////////////////////
		// Abstract
		///////////////////////////////////////////////////////////////
		virtual void update() = 0;

		virtual void fixedUpdate() = 0;

		virtual void draw(sf::RenderWindow& window) = 0;

		virtual void onInput(sf::Event& event) = 0;

		virtual void onEvent(GameEvent& event) = 0;

		virtual sf::FloatRect getBoundingBox() = 0;

		virtual void setPosition(float x, float y) = 0;

		virtual void setColor(int r, int g, int b, int a) = 0;

	};

}
