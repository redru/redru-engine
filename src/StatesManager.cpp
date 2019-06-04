#include "..\include\REDRU\Managers\StatesManager.hpp"

namespace re {

	StatesManager::StatesManager(RedruEngine& engine) : engine(engine) {
		cout << "[StatesManager] created" << endl;
	}

	void StatesManager::initialize() {
		cout << "[StatesManager] initialized" << endl;
	}

}
