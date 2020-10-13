#pragma once
#include "Vec3f.h"


class Light {
public:
    Vec3f position;
    double intensity;

    Light() {
        position = Vec3f();
        intensity = 0.0f;
    }

    Light(Vec3f position_, double intensity_) {
        position = position_;
        intensity = intensity_;
    }

};