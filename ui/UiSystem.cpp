#include "UiSystem.h"
#include "UiConstraints.h"
#include "UiBlockRenderer.h"
#include "../log/Log.h"

namespace flash {
    void UiSystem::update(float deltaTime) {
        Log::debug("UiSystem::update() called");

        for (auto& e : m_updatedEntities) {
            auto& constraints = m_ecs->getComponent<UiConstraints>(e);
            auto& blockRenderer = m_ecs->getComponent<UiBlockRenderer>(e);

            // TODO: Constraint calculation
            blockRenderer.dimensions = { 0, 0, 100, 100 };
        }
    }

    void UiSystem::render() {
        Log::debug("UiSystem::render() called");

        for (auto& e : m_entities) {
            const auto& blockRenderer = m_ecs->getComponent<UiBlockRenderer>(e);

            // drawQuad(blockRenderer.dimensions, blockRenderer.color);
        }
    }
}