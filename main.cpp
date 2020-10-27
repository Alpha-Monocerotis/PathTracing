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
    scene.addSceneObject(SceneObject(Vec3f(0.0f, 0.0f, 40.0f), Vec3f(1.0f, 0.0f, 1.0f), Vec3f(), 25.0f));
    Image image = Image(width, height);
    Light light = Light(Vec3f(0.0f, 50.0f, 50.0f), 2000);
    Vec3f camera_origin = Vec3f(0,0,0);
    for(int i=0;i<width;i++) {
        for(int j=0;j<height;j++) {
            double cur_point_x = (i - 250 + 0.5) / 20;
            double cur_point_y = (j - 250 + 0.5) / 20;
            Vec3f image_point = Vec3f(cur_point_x, cur_point_y, 10.0f);
            Ray ray = Ray(camera_origin, (image_point - camera_origin).norm());
            // cout<<"Camera Origin:"<<camera_origin<<endl<<"Direction: "<< ray.direction<<endl;
            Vec3f hit_point = Vec3f();
            if(scene.getIntersection(ray, hit_point)) {
                Vec3f color = Vec3f(1.0,1,0.5) * light.intensity * max(double(0), (hit_point - Vec3f(0.0f, 0.0f, 40.0f)).norm().dot((light.position - hit_point).norm()));
                image.setPixel(i, j, color);
            }
        }
    }
    image.wirte_image("./x.raw");
    return 0;

}