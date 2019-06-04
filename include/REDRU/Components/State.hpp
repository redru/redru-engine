#pragma once

namespace re {

	class State {

	public:

		virtual void onInit() = 0;

		virtual void onClose() = 0;

		virtual void update() = 0;

		virtual void fixedUpdate() = 0;

		virtual void draw() = 0;

	};

}
