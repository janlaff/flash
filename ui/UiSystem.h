#pragma once

#include "../ecs/EntityComponentSystem.h"

namespace flash {
    class UiSystem : public flash::System {
    public:
        using System::System;

        void update(float deltaTime);
        void render();
    };
}