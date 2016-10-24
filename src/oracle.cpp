#include <iostream>
#include <random>

using namespace std;

int main () {
    double p = 0.25;
    int sum = 0;
    // constructing a random_device that will act as the probabilistic oracle
    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<> distrib({ 1-p, p });
    // 1 - p is the probability for zero
    for (int i = 0; i < 1000; i++) {
        sum += distrib(gen);
    }
    cout << sum << endl;

    return 0;
}