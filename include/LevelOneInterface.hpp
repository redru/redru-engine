#pragma once
#include "REDRU/RedruEngine.hpp"

namespace re {

	using namespace std;

	class LevelOneInterface {

	private:

		RedruEngine& engine;

	public:

		LevelOneInterface(RedruEngine& engine);

		void draw();

	};

}
