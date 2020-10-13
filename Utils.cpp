#include "Utils.h"
#include "Vec3f.h"
#include "RNG.h"
#include <stdlib.h>
#include<ctime>
#include <iostream>

using namespace std;

Vec3f getRandomVec3f(const Vec3f &low_bound, const Vec3f &up_bound, RNG rng) {
    return Vec3f(rng.getRandomFloat(), rng.getRandomFloat(), rng.getRandomFloat());
}