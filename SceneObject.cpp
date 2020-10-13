#include "SceneObject.h"
#include <math.h>
SceneObject:: SceneObject() {
    position = Vec3f();
    color = Vec3f();
    emission = Vec3f();
    r = 0.0;
}

SceneObject::SceneObject(Vec3f position_, Vec3f color_, Vec3f emission_, double r_) {
    position = position_;
    color = color_;
    emission = emission_;
    r = r_;
}

bool SceneObject::intersects(Ray ray, Vec3f& hit_point) {
    double distance = (position - ray.origin).getLength();
    Vec3f dis_vector = ray.origin - position;
    double delta = pow(ray.direction.dot(dis_vector), 2.0) - ray.direction.dot(ray.direction) * (dis_vector.dot(dis_vector) - r * r);
    double t = min(-ray.direction.dot(dis_vector) + sqrt(delta) / ray.direction.dot(ray.direction), -ray.direction.dot(dis_vector) - sqrt(delta) / ray.direction.dot(ray.direction));
    if (t > 1e-8)
        hit_point = ray.origin + ray.direction * t;
    return delta > 1e-8 && t > 0;
}