#pragma once
#include "REDRU/Components/GameObject.hpp"
#include "REDRU/RedruEngine.hpp"

namespace re {

	using namespace std;

	class CardObject : public GameObject {

	private:

		/////////////////////////////////////////////////////////////
		// Members
		/////////////////////////////////////////////////////////////

		RedruEngine& engine;

		sf::Sprite frontSprite;

		sf::Sprite backSprite;

		bool faceUp = false;

	public:

		//////////////////////////////////////////////////////////////
		// Constructor
		//////////////////////////////////////////////////////////////

		CardObject(string id, RedruEngine& engine, sf::Texture& frontTexture, sf::Texture& backTexture);

		//////////////////////////////////////////////////////////////
		// GameObject
		//////////////////////////////////////////////////////////////

		void update() override;

		void fixedUpdate() override;

		void draw(sf::RenderWindow& window) override;

		void onInput(sf::Event& event) override;

		void onEvent(GameEvent& event) override;

		sf::FloatRect getBoundingBox() override;

		void setPosition(float x, float y) override;

		void setColor(int r, int g, int b, int a) override;

		///////////////////////////////////////////////////////////////
		// CardObject
		///////////////////////////////////////////////////////////////

		void setFaceUp(bool faceUp);

		bool& isFaceUp();

	};

}
