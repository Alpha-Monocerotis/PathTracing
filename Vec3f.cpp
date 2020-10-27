//
// Created by MENGYANG LIU on 2020/9/15.
//

#include "Vec3f.h"
#include "Utils.h"
#include <vector>
#include <cmath>

Vec3f::Vec3f() {
    x = 0;
    y = 0;
    z = 0;
}

Vec3f::Vec3f(const Vec3f &other) {
    x = other.x; 
    y = other.y;
    z = other.z;
}

Vec3f::Vec3f(double x_, double y_, double z_) {
    x = x_;
    y = y_;
    z = z_;
}

void Vec3f::operator = (const Vec3f& other) {
    x = other.x;
    y= other.y;
    z = other.z;
}
Vec3f Vec3f::operator + (const Vec3f& other) const {
    return Vec3f(x + other.x, y + other.y, z + other.z);
}

Vec3f Vec3f::operator - (const Vec3f& other) const {
    return Vec3f(x - other.x, y - other.y, z  - other.z);
}

Vec3f Vec3f::operator * (double factor) const {
    return Vec3f(x * factor, y * factor, z * factor);
}

double Vec3f::dot(const Vec3f& other) {
    return x * other.x + y * other.y + z * other.z;
}

Vec3f Vec3f::mul(const Vec3f& other) {
    return Vec3f(x * other.x, y * other.y, z * other.z);
}

Vec3f Vec3f::norm() {
    return *this * (1 / sqrt(x * x + y * y + z * z));
}

double Vec3f::getLength() {
    return sqrt(x * x + y * y + z * z);
};

Vec3f Vec3f::operator % (const Vec3f& other) {
    return Vec3f(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

std::vector<LL> Vec3f::getIntVec3f() {
    std::vector<LL> vec;
    vec.push_back(LL(x));
    vec.push_back(LL(y));
    vec.push_back(LL(z));
    return vec;
}

ostream& operator<<(ostream &os, const Vec3f &vec) {
    os << vec.x << " " << vec.y << " " << vec.z;
    return os;
}