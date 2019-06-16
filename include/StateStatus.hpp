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
	bool ai;
	int points;
};

typedef vector<unique_ptr<PlayerStatus>> Players;

class StateStatus {

private:
	 
	Players players;

	int currentPlayer;

	int rounds;

	bool playingVsAi;

public:

	StateStatus(vector<PlayerStatus*> players);

	int& addPoints(int pointsToAdd, int player = -1);

	void nextPlayer();

	void nextRound();

	bool isCurrentPlayerAi();

	void setCurrentPlayer(int currentPlayer);

	int& getCurrentPlayer();

	Players& getPlayers();

	int& getRounds();

	void setPlayingVsAi(bool playingVsAi);

	bool& getPlayingVsAi();

};
