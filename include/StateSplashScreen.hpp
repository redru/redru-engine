#pragma once
#include <math.h>
#include <memory>

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include "REDRU/Components/State.hpp"
#include "REDRU/Components/GenericGameObject.hpp"
#include "REDRU/Data/StateInitializationData.hpp"
#include "REDRU/RedruEngine.hpp"

using namespace std;

class StateSplashScreen : public re::State {

private:

	re::RedruEngine& engine;

	unique_ptr<re::GameObject> splashImage;

	int elapsed;

public:

	StateSplashScreen(re::RedruEngine& engine);

	void onInit(shared_ptr<re::StateInitializationData> data) override;

	void onClose() override;

	void reset() override;

	void update() override;

	void fixedUpdate() override;

	void draw() override;

	void onInput(sf::Event& event) override;

	void onEvent(re::GameEvent& event) override;

};
