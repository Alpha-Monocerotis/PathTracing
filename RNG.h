#pragma once
typedef long long LL;

class RNG {
public:
    LL offset;

    RNG();

    double getRandomFloat();
};