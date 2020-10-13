#include "Image.h"
#pragma pack(2)
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef long LONG;

#include "Vec3f.h"

struct BmpFileHeader
{
    WORD    bfType;
    DWORD   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    DWORD   bfOffBits;
};

struct BmpInfoHeader
{
    DWORD   biSize;             
    LONG    biWidth;            
    LONG    biHeight;           
    WORD    biPlanes;           
    WORD    biBitCount;         
    DWORD   biCompression;      
    DWORD   biSizeImage;        
    LONG    biXPelsPerMeter;    
    LONG    biYPelsPerMeter;    
    DWORD   biClrUsed;          
    DWORD   biClrImportant; 
};

struct RGBType
{
    unsigned char r;
    unsigned char g;
    unsigned char b;

    void set(unsigned char r1, unsigned char g1, unsigned char b1)
    {
        r = r1;
        g = g1;
        b = b1;
    }
};

void saveBmp(const char *fileName, int w, int h, RGBType *data)
{
    int size = 4 * w * h;

    //设置bmpfileheader的各种数值
    BmpFileHeader fileHeader;
    fileHeader.bfType = 0x4D42;//0x4d42即字母 'B''M'
    fileHeader.bfReserved1 = 0;//保留位1
    fileHeader.bfReserved2 = 0;//保留位2
    fileHeader.bfSize = 54 + size;//文件总长度 文件头(54字节) + 图像数据(size)
    fileHeader.bfOffBits = 54;//文件头长度

    //设置infoheader的值
    BmpInfoHeader infoHeader = {0};
    infoHeader.biSize = 40;//infoheader的长度
    infoHeader.biHeight = -h;//高度
    infoHeader.biWidth = w;//宽度
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 24;//颜色位数。一般为24
    infoHeader.biSizeImage = 0;//默认为0
    infoHeader.biCompression = 0;//压缩率 ，默认为0


    //将传入的RGB数值写入文件中
    FILE *output = fopen(fileName, "wb");
    if (output)
    {
        fwrite(&fileHeader, 14, 1, output);
        fwrite(&infoHeader, 40, 1, output);
        for (int i = 0; i < w * h; ++i)
        {
            RGBType rgb = data[i];
            unsigned char color[3] = {rgb.r, rgb.g, rgb.b};
            fwrite(color, 3, 1, output);
        }
        fclose(output);
    }
}


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

void Image::wirte_image(string filename) {
    int n = width * height;

    RGBType *pixels = new RGBType[n];
    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            int i = y * width + x;
            int r = int(image[x][y].x > 255 ? 255 : image[x][y].x);
            int g = int(image[x][y].y > 255 ? 255 : image[x][y].y);
            int b = int(image[x][y].z > 255 ? 255 : image[x][y].z);
            pixels[i].set(r,g,b);
        }
    }
    saveBmp(filename.c_str(), width, height, pixels);
}