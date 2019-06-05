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

	engine->registerTexture("TEX_SPLASH_IMAGE", "resources/splash_image.png");
	engine->registerTexture("TEX_CARD_TABLE", "resources/card_table_960_540.png");
	engine->registerTexture("TEX_MAIN_MENU", "resources/main_menu_960_540.png");
	engine->registerTexture("TEX_START_BUTTON", "resources/start_button_100_40.png");

	engine->registerState("SPLASH_SCREEN", make_shared<StateSplashScreen>(StateSplashScreen(*engine)));
	engine->registerState("MAIN_MENU", make_shared<StateMainMenu>(StateMainMenu(*engine)));

	engine->changeState("SPLASH_SCREEN", true);

	int exitCode = engine->start();

	delete engine;

	return exitCode;
}
