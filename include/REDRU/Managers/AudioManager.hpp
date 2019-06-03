#pragma once
#include <iostream>

namespace re {

	class RedruEngine;

	class AudioManager {

	private:
		RedruEngine& engine;

	public:
		AudioManager(RedruEngine& engine);

		void initialize();

	};

}
