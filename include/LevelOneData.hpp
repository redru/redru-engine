#pragma once
#include <string>
#include <vector>

#include "REDRU/Data/StateInitializationData.hpp"
#include "StateStatus.hpp"

using namespace std;

class LevelOneData : public re::StateInitializationData {

private:

	vector<PlayerStatus*> players;

	bool playingVsAi;

public:

	LevelOneData(vector<PlayerStatus*> players = vector<PlayerStatus*>(0), bool playingVsAi = false);

	void setPlayers(vector<PlayerStatus*> players);

	vector<PlayerStatus*>& getPlayers();

	void setPlayingVsAi(bool playingVsAi);

	bool& getPlayingVsAi();

};
