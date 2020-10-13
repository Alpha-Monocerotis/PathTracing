#pragma once
#include "Vec3f.h"

class Ray {

public:
    Vec3f origin;
    Vec3f direction;

    Ray();
    Ray(Vec3f origin_, Vec3f direction_);
    Vec3f getPoint(double t);
    
};