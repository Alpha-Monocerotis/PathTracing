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
    scene.addSceneObject(SceneObject(Vec3f(0.0f, 0.0f, 40.0f), Vec3f(1.0f, 0.0f, 1.0f), Vec3f(), 20.0f));
    Image image = Image(100, 100);
    Light light = Light(Vec3f(0.0f, 30.0f, 20.0f), 400);
    Vec3f camera_origin = Vec3f(0,0,0);
    for(int i=0;i<100;i++) {
        for(int j=0;j<100;j++) {
            double cur_point_x = (i - 50 + 0.5) / 10;
            double cur_point_y = (j - 50 + 0.5) / 10;
            Vec3f image_point = Vec3f(cur_point_x, cur_point_y, 10.0f);
            Ray ray = Ray(camera_origin, (image_point - camera_origin).norm());
            // cout<<"Camera Origin:"<<camera_origin<<endl<<"Direction: "<< ray.direction<<endl;
            Vec3f hit_point = Vec3f();

            if(scene.getIntersection(ray, hit_point)) {
                Vec3f color = Vec3f(1,0,1) * light.intensity * max(double(0), (hit_point - Vec3f(0.0f, 0.0f, 40.0f)).norm().dot((light.position - hit_point).norm()));
                cout<<color<<endl;
                image.setPixel(i, j, color);
            }
        }
    }
    image.wirte_image("./x.bmp");
    return 0;

}