#include "StateStatus.hpp"

StateStatus::StateStatus(vector<string> players) : players(players), playersPoints() {
	for (auto it = players.begin(); it != players.end(); it++) {
		playersPoints[*it] = 0;
	}

	spdlog::debug("[StateStatus] level one initialized with " + to_string(players.size()) + " players");
}

int StateStatus::getPlayersCount() {
	return players.size();
}

int StateStatus::addPoints(string playerName, int pointsToAdd) {
	auto it = playersPoints.find(playerName);

	if (it == playersPoints.end()) {
		spdlog::error("[StateStatus] player '" + playerName + "' does not exist and points could not be added");
	}

	it->second = it->second + pointsToAdd;

	return it->second;
}

const map<string, int>& StateStatus::getPoints() {
	return playersPoints;
}

int StateStatus::getPlayerPoints(string playerName) {
	auto it = playersPoints.find(playerName);

	if (it == playersPoints.end()) {
		spdlog::error("[StateStatus] player '" + playerName + "' does not exist and points could no be retrieved");
	}

	return it->second;
}

vector<string>& StateStatus::getPlayers() {
	return players;
}

void StateStatus::nextPlayer() {
	auto it = find(players.begin(), players.end(), currentPlayer);

	it++;

	if (it == players.end())
		currentPlayer = players[0];
	else
		currentPlayer = *it;
}

void StateStatus::setCurrentPlayer(string currentPlayer) {
	this->currentPlayer = currentPlayer;
}

string& StateStatus::getCurrentPlayer() {
	return currentPlayer;
}
