#include "REDRU/RedruEngine.hpp"

using namespace std;
using namespace re;

int main() {
	RedruEngine engine;

	engine.initialize();

	return engine.start();
}
