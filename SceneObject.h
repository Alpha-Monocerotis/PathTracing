#pragma once
#include "Vec3f.h"
#include "Ray.h"

class SceneObject {
public:
    Vec3f position;
    Vec3f color;
    Vec3f emission;
    double r;

    SceneObject();
    SceneObject(Vec3f position_, Vec3f color_, Vec3f emission_, double r_);
    bool intersects(Ray ray, Vec3f& hit_point);
};