#include "StateStatus.hpp"

StateStatus::StateStatus(vector<PlayerStatus*> players) :
	players(players.size()),
	currentPlayer(-1),
	rounds(1),
	playingVsAi(false) {

	for (int i = 0; i < players.size(); i++) {
		this->players[i].reset(players[i]);
	}

	spdlog::debug("[StateStatus] level one initialized with " + to_string(players.size()) + " players");
}

int& StateStatus::addPoints(int pointsToAdd, int player) {
	// If player is out array, log error
	if (player >= (int) players.size()) {
		spdlog::error("[StateStatus] player '" + to_string(player) + "' does not exist and points could not be added");

		exit(1);
	}

	// If player == -1, add points to current player
	PlayerStatus& playerStatus = *players[player == -1 ? currentPlayer : player];

	playerStatus.points = playerStatus.points + pointsToAdd;

	return playerStatus.points;
}

void StateStatus::nextPlayer() {
	currentPlayer = currentPlayer + 1 >= players.size() ?
		0 :
		currentPlayer + 1;
}

void StateStatus::nextRound() {
	rounds++;
}

bool StateStatus::isCurrentPlayerAi() {
	return players[currentPlayer]->ai;
}

void StateStatus::setCurrentPlayer(int currentPlayer) {
	if (currentPlayer >= (int) players.size()) {
		spdlog::error("[StateStatus] player '" + to_string(currentPlayer) + "' does not exist and could not be selected as current");
	}

	this->currentPlayer = currentPlayer;
}

int& StateStatus::getCurrentPlayer() {
	return currentPlayer;
}

Players& StateStatus::getPlayers() {
	return players;
}

int& StateStatus::getRounds() {
	return rounds;
}

void StateStatus::setPlayingVsAi(bool playingVsAi) {
	this->playingVsAi = playingVsAi;
}

bool& StateStatus::getPlayingVsAi() {
	return playingVsAi;
}
