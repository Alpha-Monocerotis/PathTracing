#pragma once
#include "SceneObject.h"
#include "Ray.h"
#include <vector>

class Scene {
public:
    std::vector<SceneObject> sceneObjects;
    Scene();
    void addSceneObject(SceneObject object);
    bool getIntersection(Ray ray, Vec3f& hit_point, SceneObject& obj);
};