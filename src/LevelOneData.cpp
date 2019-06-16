#include "LevelOneData.hpp"

LevelOneData::LevelOneData(vector<PlayerStatus*> players, bool playingVsAi) :
	players(players),
	playingVsAi(playingVsAi) {
}

void LevelOneData::setPlayers(vector<PlayerStatus*> players) {
	this->players = players;
}

vector<PlayerStatus*>& LevelOneData::getPlayers() {
	return players;
}

void LevelOneData::setPlayingVsAi(bool playingVsAi) {
	this->playingVsAi = playingVsAi;
}

bool& LevelOneData::getPlayingVsAi() {
	return playingVsAi;
}
