#pragma once

namespace flash {
    struct UiDimensions {
        int x;
        int y;
        int width;
        int height;
    };

    enum UiColor {
        black,
        white
    };

    struct Vec3 {
        float x, y, z;
    };

    static constexpr Vec3 colorTable[] = {
        [UiColor::black] = { 0, 0, 0 },
        [UiColor::white] = { 255, 255, 255 }
    };

    struct UiBlockRenderer {
        UiDimensions dimensions;
        UiColor color;
    };
}