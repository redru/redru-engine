#include <spdlog/spdlog.h>
#include "REDRU/RedruEngine.hpp"

#include "StateSplashScreen.hpp"
#include "StateMainMenu.hpp"

using namespace std;
using namespace re;

int main() {
	spdlog::set_level(spdlog::level::debug);
	RedruEngine* engine = new RedruEngine();

	engine->initialize();

	engine->registerState("SPLASH_SCREEN", make_shared<StateSplashScreen>(StateSplashScreen(*engine)));
	engine->registerState("MAIN_MENU", make_shared<StateMainMenu>(StateMainMenu(*engine)));

	engine->changeState("SPLASH_SCREEN", true);

	int exitCode = engine->start();

	delete engine;

	return exitCode;
}
