#include <spdlog/spdlog.h>
#include "REDRU/RedruEngine.hpp"

#include "StateSplashScreen.hpp"
#include "StateMainMenu.hpp"
#include "StateLevelOneSingle.hpp"

using namespace std;
using namespace re;

int main() {
	spdlog::set_level(spdlog::level::debug);

	RedruEngine* engine = new RedruEngine();

	engine->initialize();

	engine->registerTexture("TEX_SPLASH_IMAGE", "resources/splash_image_1920_1080.png");
	engine->registerTexture("TEX_CARD_TABLE", "resources/card_table_1920_1080.png");
	engine->registerTexture("TEX_MAIN_MENU", "resources/main_menu_background_1920_1080.png");
	engine->registerTexture("TEX_START_BUTTON", "resources/start_button_100_40.png");
	engine->registerTexture("TEX_EXIT_BUTTON", "resources/exit_button_100_40.png");

	engine->registerTexture("TEX_CARD_1", "resources/card_dalaran_flame_150_220.png");
	engine->registerTexture("TEX_CARD_2", "resources/card_gnome_150_220.png");
	engine->registerTexture("TEX_CARD_3", "resources/card_lunar_new_year_150_220.png");
	engine->registerTexture("TEX_CARD_4", "resources/card_maraad_150_220.png");

	engine->registerState("SPLASH_SCREEN", make_shared<StateSplashScreen>(StateSplashScreen(*engine)));
	engine->registerState("MAIN_MENU", make_shared<StateMainMenu>(StateMainMenu(*engine)));
	engine->registerState("LEVEL_ONE_SINGLE", make_shared<StateLevelOneSingle>(StateLevelOneSingle(*engine)));

	engine->changeState("SPLASH_SCREEN", true);

	int exitCode = engine->start();

	delete engine;

	return exitCode;
}
