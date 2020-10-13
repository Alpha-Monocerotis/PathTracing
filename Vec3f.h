#pragma once
#include <vector>
#include <iostream>
using namespace std;

typedef long long LL;


class Vec3f {
public:
    double x;
    double y;
    double z;

    Vec3f();
    Vec3f(const Vec3f& other);
    Vec3f(double x_, double y_, double z_);
    void operator = (const Vec3f& other);
    Vec3f operator + (const Vec3f& other) const;
    Vec3f operator - (const Vec3f& other) const;
    Vec3f operator * (double factor) const;
    friend ostream& operator<<(ostream &os, const Vec3f &vec);
    double dot(const Vec3f& other);
    double getLength();
    Vec3f mul(const Vec3f& other);
    Vec3f norm();
    Vec3f operator % (const Vec3f& other);
    std::vector<LL> getIntVec3f();
};
