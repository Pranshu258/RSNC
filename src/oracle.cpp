#include <iostream>
#include <random>
#include "point.h"

using namespace std;

// This oracle compares two points on a given attribute
// with the error probability of p
int oracle(point a, point b, int d) {
    double p = 0.25;
    random_device rd;
    mt19937 gen(rd());
    if (a.attribute[d] < b.attribute[d]) {
        discrete_distribution<> distrib({ 1-p, p });
        return distrib(gen);
    } else {
        discrete_distribution<> distrib({ p, 1-p });
        return distrib(gen);
    }
}

int main() {
    return 0;
}