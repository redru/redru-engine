#pragma once
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include <spdlog/spdlog.h>

using namespace std;

class StateStatus {

private:

	vector<string> players;

	map<string, int> playersPoints;

	string currentPlayer;

public:

	StateStatus(vector<string> players);

	int getPlayersCount();

	int addPoints(string playerName, int pointsToAdd);

	const map<string, int>& getPoints();

	int getPlayerPoints(string playerName);

	vector<string>& getPlayers();

	void nextPlayer();

	void setCurrentPlayer(string currentPlayer);

	string& getCurrentPlayer();

};
