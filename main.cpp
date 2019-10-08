#include <iostream>

#include "log/Log.h"
#include "log/ConsoleLogger.h"
#include "ecs/EntityComponentSystem.h"
#include "ui/UiSystem.h"
#include "ui/UiConstraints.h"
#include "ui/UiBlockRenderer.h"

int main() {
    auto logger = std::make_shared<flash::ConsoleLogger>();
    flash::Log::addLogger(logger);
    flash::Log::debug("Engine started");

    auto ecs = flash::EntityComponentSystem();

    auto uiSystem = ecs.registerSystem<flash::UiSystem>();
    auto uiSystemSignature = flash::Signature();
    ecs.registerComponent<flash::UiBlockRenderer>();
    ecs.registerComponent<flash::UiConstraints>();
    uiSystemSignature.set(ecs.getComponentType<flash::UiBlockRenderer>());
    uiSystemSignature.set(ecs.getComponentType<flash::UiConstraints>());
    ecs.setSystemSignature<flash::UiSystem>(uiSystemSignature);

    while (true) {

    }

    flash::Log::debug("Engine shutdown");

    return 0;
}
