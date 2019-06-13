#include "LevelOneInterface.hpp"

namespace re {

	LevelOneInterface::LevelOneInterface(RedruEngine& engine) : engine(engine) {
		if (!font.loadFromFile("resources/Gilbert-Color_Bold_Preview5.otf")) {
			exit(1);
		}

		text.setFont(font);
		text.setCharacterSize(36);
		text.setString("Player 1");
	}

	void LevelOneInterface::draw() {
		engine.getGraphicsManager()->getWindow().draw(text);
	}

}
