#pragma once

#include "Vec3f.h"

class Image {
    public:
        vector< vector<Vec3f> > image;
        int height;
        int width;
        Image();
        Image(int height_, int width_);
        void setPixel(int x, int y, Vec3f color);
        void wirte_image(string filename);
        
};