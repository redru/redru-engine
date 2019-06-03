#include "..\include\REDRU\Managers\StatesManager.hpp"

namespace re {

	StatesManager::StatesManager(RedruEngine& engine) : engine(engine) {
	}

	void StatesManager::initialize() {
		cout << "StatesManager initialized" << endl;
	}

}
