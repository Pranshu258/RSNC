#include "header.h"

// This oracle compares two points on a given attribute
// with the error probability of p
int oracle(point a, point b, int d) {
    double p = 0.25;
    std::random_device rd;
    std::mt19937 gen(rd());
    if (a.attribute[d] < b.attribute[d]) {
        std::discrete_distribution<> distrib({ 1-p, p });
        return distrib(gen);
    } else {
        std::discrete_distribution<> distrib({ p, 1-p });
        return distrib(gen);
    }
}