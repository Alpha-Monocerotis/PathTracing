#include "Ray.h"
#include "Vec3f.h"

Ray::Ray() {
    origin = Vec3f();
    direction = Vec3f();
}

Ray::Ray(Vec3f origin_, Vec3f direction_) {
    origin = origin_;
    direction = direction_;
}

Vec3f Ray::getPoint(double t) {
    return origin + direction * t;
}