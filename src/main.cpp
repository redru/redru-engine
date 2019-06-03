#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "REDRU/RedruEngine.hpp"

using namespace std;
using namespace re;

int main() {
	// unique_ptr<RedruEngine> engine = make_unique<RedruEngine>(RedruEngine());
	// unique_ptr<RedruEngine> engine;
	// engine.reset(new RedruEngine());
	RedruEngine engine;

	engine.initialize();

	return engine.start();
}
