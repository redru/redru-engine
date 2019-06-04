#pragma once
#include <iostream>
#include <spdlog/spdlog.h>

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
