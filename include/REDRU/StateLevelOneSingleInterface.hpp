#pragma once
#include "REDRU/RedruEngine.hpp"

namespace re {

	using namespace std;

	class StateLevelOneInterface {

	private:

		RedruEngine& engine;

	public:

		StateLevelOneInterface(RedruEngine& engine);

		void draw();

	};

}
