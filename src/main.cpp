#include <spdlog/spdlog.h>
#include "REDRU/RedruEngine.hpp"

#include "StateSplashScreen.hpp"
#include "StateMainMenu.hpp"
#include "StateLevelOne.hpp"

using namespace std;

int main() {
	spdlog::set_level(spdlog::level::debug);

	re::RedruEngine* engine = new re::RedruEngine();

	engine->initialize();

	// Fonts
	engine->registerFont("UI_FONT", "resources/Gilbert-Color_Bold_Preview5.otf");

	// Textures
	engine->registerTexture("TEX_SPLASH_IMAGE", "resources/splash_image_1920_1080.png");
	engine->registerTexture("TEX_CARD_TABLE", "resources/card_table_1920_1080.png");
	engine->registerTexture("TEX_MAIN_MENU", "resources/main_menu_background_1920_1080.png");
	engine->registerTexture("TEX_START_BUTTON", "resources/start_button_100_40.png");
	engine->registerTexture("TEX_EXIT_BUTTON", "resources/exit_button_100_40.png");

	engine->registerTexture("TEX_CARD_1", "resources/card_dalaran_flame_150_220.png");
	engine->registerTexture("TEX_CARD_2", "resources/card_gnome_150_220.png");
	engine->registerTexture("TEX_CARD_3", "resources/card_lunar_new_year_150_220.png");
	engine->registerTexture("TEX_CARD_4", "resources/card_maraad_150_220.png");

	engine->registerTexture("TEX_CARD_FRONT_1", "resources/arthas_150_220.png");
	engine->registerTexture("TEX_CARD_FRONT_2", "resources/jaina_150_220.png");
	engine->registerTexture("TEX_CARD_FRONT_3", "resources/medivh_150_220.png");
	engine->registerTexture("TEX_CARD_FRONT_4", "resources/sylvanas_150_220.png");
	engine->registerTexture("TEX_CARD_FRONT_5", "resources/thrall_150_220.png");
	engine->registerTexture("TEX_CARD_FRONT_6", "resources/troll_150_220.png");

	// Musics
	engine->registerMusic("BACKGROUND", "resources/ffviii_shuffle_or_boogie.ogg");

	// Sounds
	engine->registerSound("CARD_MATCH", "resources/Coin01.ogg");

	// States
	engine->registerState("SPLASH_SCREEN", new StateSplashScreen(*engine));
	engine->registerState("MAIN_MENU", new StateMainMenu(*engine));
	engine->registerState("LEVEL_ONE", new StateLevelOne(*engine));

	// Initialize
	engine->changeState("SPLASH_SCREEN", true);

	int exitCode = engine->start();

	delete engine;

	return exitCode;
}
