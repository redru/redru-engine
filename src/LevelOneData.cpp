#include "LevelOneData.hpp"

void LevelOneData::setPlayerNames(vector<string> playerNames) {
	this->playerNames = playerNames;
}

vector<string>& LevelOneData::getPlayerNames() {
	return playerNames;
}
