#include "Vec3f.h"
#include "Utils.h"
#include "RNG.h"
#include "Scene.h"
#include "SceneObject.h"
#include "Image.h"
#include "Light.h"
#include <iostream>

int main() {

    Scene scene = Scene();
    int width = 500;
    int height = 500;
    // scene.addSceneObject(SceneObject(Vec3f(60.0f, 50.0f, 40.0f), Vec3f(1.0f, 0.2f, 0.0f), Vec3f(), 10.0f));
    scene.addSceneObject(SceneObject(Vec3f(40.0f, 0.0f, 90.0f), Vec3f(1.0f, 0.0f, 1.0f), Vec3f(), 50.0f));
    scene.addSceneObject(SceneObject(Vec3f(-40.0f, -20.0f, 60.0f), Vec3f(0.2f, 0.2f, 1.0f), Vec3f(), 30.0f));
    // scene.addSceneObject(SceneObject(Vec3f(0.0f, 0.0f, 40.0f), Vec3f(1.0f, 0.1f, 0.3f), Vec3f(), 30.0f));
    // scene.addSceneObject(SceneObject(Vec3f(0.0f, 30.0f, 20.0f), Vec3f(0.5f, 0.2f, 0.0f), Vec3f(), 10.0f));

    Image image = Image(width, height);
    Light light0 = Light(Vec3f(0.0f, 150.0f, 80.0f), 100);
    Light light1 = Light(Vec3f(0.0f, -150.0f, 40.0f), 200);
    Light light2 = Light(Vec3f(-150.0f, 0.0f, 80.0f), 100);
    Light light3 = Light(Vec3f(150.0f, 0.0f, 40.0f), 200);
    Vec3f camera_origin = Vec3f(0,0,10);
    for(int i=0;i<width;i++) {
        for(int j=0;j<height;j++) {
            double cur_point_x = (i - 250 + 0.5);
            double cur_point_y = (j - 250 + 0.5);
            Vec3f image_point = Vec3f(cur_point_x, cur_point_y, 30.0f);
            Ray ray = Ray(camera_origin, (image_point - camera_origin).norm());
            // cout<<"Camera Origin:"<<camera_origin<<endl<<"Direction: "<< ray.direction<<endl;
            Vec3f hit_point = Vec3f();
            SceneObject obj = SceneObject();
            if(scene.getIntersection(ray, hit_point, obj)) {
                Vec3f color = obj.color * light0.intensity * max(double(0), (hit_point - Vec3f(0.0f, 0.0f, 40.0f)).norm().dot((light0.position - hit_point).norm()));
                color = color + obj.color * light1.intensity * max(double(0), (hit_point - Vec3f(0.0f, 0.0f, 40.0f)).norm().dot((light1.position - hit_point).norm()));
                color = color + obj.color * light2.intensity * max(double(0), (hit_point - Vec3f(0.0f, 0.0f, 40.0f)).norm().dot((light2.position - hit_point).norm()));\
                color = color + obj.color * light3.intensity * max(double(0), (hit_point - Vec3f(0.0f, 0.0f, 40.0f)).norm().dot((light3.position - hit_point).norm()));
                image.setPixel(i, j, color);
            }
        }
    }
    image.wirte_image("./x.raw");
    return 0;
}