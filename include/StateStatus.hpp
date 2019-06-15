#pragma once
#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <spdlog/spdlog.h>

using namespace std;

struct PlayerStatus {
	string name;
	int points;
};

typedef vector<unique_ptr<PlayerStatus>> Players;

class StateStatus {

private:
	 
	Players players;

	int currentPlayer;

public:

	StateStatus(vector<string> playerNames);

	// TODO Not working, fix
	int& getPlayersCount();

	int& addPoints(int pointsToAdd, int player = -1);

	void nextPlayer();

	void setCurrentPlayer(int currentPlayer);

	int& getCurrentPlayer();

	Players& getPlayers();

};
