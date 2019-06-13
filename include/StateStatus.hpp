#pragma once
#include <map>
#include <string>
#include <vector>

#include <spdlog/spdlog.h>

using namespace std;

class StateStatus {

private:

	int playersCount;

	vector<string> players;

	map<string, int> playersPoints;

public:

	StateStatus(vector<string> players);

	int getPlayersCount();

	int addPoints(string playerName, int pointsToAdd);

	const map<string, int>& getPoints();

	int getPlayerPoints(string playerName);

};
