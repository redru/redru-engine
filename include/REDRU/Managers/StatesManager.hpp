#pragma once
#include <iostream>

namespace re {

	using namespace std;

	class RedruEngine;

	class StatesManager {

	private:
		RedruEngine& engine;


	public:
		StatesManager(RedruEngine& engine);

		void initialize();

	};

}
