#pragma once
#include <SFML/Graphics.hpp>

namespace re {

	class GameObject {

	public:

		virtual void update() = 0;

		virtual void fixedUpdate() = 0;

		virtual void draw() = 0;

	};

}
