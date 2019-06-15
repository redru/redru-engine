#include "StateStatus.hpp"

StateStatus::StateStatus(vector<string> playerNames) : players(playerNames.size()), currentPlayer(-1) {
	for (int i = 0; i < playerNames.size(); i++) {
		PlayerStatus* playerStatus = new PlayerStatus();
		playerStatus->name = playerNames[i];
		playerStatus->points = 0;

		players[i].reset(playerStatus);
	}

	spdlog::debug("[StateStatus] level one initialized with " + to_string(players.size()) + " players");
}

// TODO Not working, fix
int& StateStatus::getPlayersCount() {
	int size = static_cast<int>(players.size());

	return size;
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

void StateStatus::setCurrentPlayer(int currentPlayer) {
	if (currentPlayer >= players.size()) {
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
