#pragma once
#include <SFML/Graphics.hpp>

#include "REDRU/Components/GameObject.hpp"
#include "REDRU/Managers/EventsManager.hpp"
#include "REDRU/RedruEngine.hpp"

using namespace std;

class CardObject : public re::GameObject {

private:

	/////////////////////////////////////////////////////////////
	// Members
	/////////////////////////////////////////////////////////////

	re::RedruEngine& engine;

	sf::Sprite frontSprite;

	sf::Sprite backSprite;

	sf::RectangleShape selectionBorder;

	int group = 0;

	bool faceUp = false;

	bool locked = false;

	bool selected = false;

public:

	//////////////////////////////////////////////////////////////
	// Constructor
	//////////////////////////////////////////////////////////////

	CardObject(string id, re::RedruEngine& engine, sf::Texture& frontTexture, sf::Texture& backTexture, int group);

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

	///////////////////////////////////////////////////////////////
	// CardObject
	///////////////////////////////////////////////////////////////

	void flip();

	void reset();

	void setFaceUp(bool faceUp);

	bool isFaceUp();

	void setGroup(int group);

	int getGroup();

	void setLocked(bool locked);

	bool isLocked();

	void setSelected(bool selected);

	bool isSelected();

	bool operator==(const CardObject& that);

};
