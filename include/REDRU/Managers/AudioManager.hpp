#pragma once

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
