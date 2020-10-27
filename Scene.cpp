#include "Scene.h"
#include "SceneObject.h"
#include "Vec3f.h"


Scene::Scene() {
    sceneObjects = std::vector<SceneObject>();
}

void Scene::addSceneObject(SceneObject object) {
    sceneObjects.push_back(object);
}

bool Scene::getIntersection(Ray ray, Vec3f& hit_point) {
    for(int i=0;i<sceneObjects.size();i++) {
        if(sceneObjects[i].intersects(ray, hit_point)) return true;
    }
    return false;
}