#include <stdio.h>

#include "Image.h"
#include "Vec3f.h"


Image::Image() {
    height = width = 0;
}
Image::Image(int height_, int width_) {
    height = height_;
    width = width_;
    image = vector< vector<Vec3f> >(height, vector<Vec3f>(width, Vec3f()));
}

void Image::setPixel(int x, int y, Vec3f color) {
    image[x][y] = color;
}

char exchange_int_char(int a)      //整型转换为字符型
{
     char b;
     switch (a)
     {
     case 0:b = '0'; break;
     case 1:b = '1'; break;
     case 2:b = '2'; break;
     case 3:b = '3'; break;
     case 4:b = '4'; break;
     case 5:b = '5'; break;
     case 6:b = '6'; break;
     case 7:b = '7'; break;
     case 8:b = '8'; break;
     case 9:b = '9'; break;
     case 10:b = 'A'; break;
     case 11:b = 'B'; break;
     case 12:b = 'C'; break;
     case 13:b = 'D'; break;
     case 14:b = 'E'; break;
     case 15:b = 'F'; break;
     default:break;
     }
     return b;
}


void Image::wirte_image(string filename) {
    int n = width * height;


    FILE* file = fopen(filename.c_str(), "wb");
    string rgb = "";
    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            int r = int(image[x][y].x > 255 ? 255 : image[x][y].x);
            int g = int(image[x][y].y > 255 ? 255 : image[x][y].y);
            int b = int(image[x][y].z > 255 ? 255 : image[x][y].z);
            char r1 = exchange_int_char(r / 16);
            char r2 = exchange_int_char(r % 16);
            char g1 = exchange_int_char(g / 16);
            char g2 = exchange_int_char(g % 16);
            char b1 = exchange_int_char(b / 16);
            char b2 = exchange_int_char(b % 16);
            rgb += r1 + r2 + g1 + g2 + b1 + b2;
            if (r+g+b != 0)
                cout<<r1<<r2<<g1<<g2<<b1<<b2<<endl;
        }
    }
    cout<<sizeof(rgb) << " " << width << " " << height <<endl;
    fwrite(rgb.c_str(),sizeof(char),width * height * 6,file);
    // fprintf(file, rgb.c_str());
    fclose(file);
}