#pragma once

#include <memory>

namespace flash {
    struct UiConstraint {};
    using UiConstraintPtr = std::shared_ptr<UiConstraint>;

    struct PixelConstraint : UiConstraint {
        float pixel;
    };

    struct RelativeConstraint : UiConstraint {
        float relative;
    };

    struct UiConstraints {
        UiConstraintPtr xConstraint;
        UiConstraintPtr yConstraint;
        UiConstraintPtr widthConstraint;
        UiConstraintPtr heightConstraint;
    };
}