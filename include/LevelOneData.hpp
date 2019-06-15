#pragma once
#include <string>
#include <vector>

#include "REDRU/Data/StateInitializationData.hpp"

using namespace std;

class LevelOneData : public re::StateInitializationData {

private:

	vector<string> playerNames;

public:

	void setPlayerNames(vector<string> playerNames);

	vector<string>& getPlayerNames();

};
