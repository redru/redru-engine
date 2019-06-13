#include "StateStatus.hpp"

StateStatus::StateStatus(vector<string> players) : players(players), playersCount(players.size()) {
	spdlog::debug("[StateStatus] level one initialized with " + to_string(playersCount) + " players");
}

int StateStatus::getPlayersCount() {
	return playersCount;
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
