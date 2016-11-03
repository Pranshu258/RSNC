#include "header.h"

model::model(int d, int* values) {
    D = d;
    dim_domains = values;
    comparators = new double**[D];

    // Create the Random Number Generator Object
    mt19937_64 rng;
    uint64_t timeSeed = chrono::high_resolution_clock::now().time_since_epoch().count();
    seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);
    for (int i = 0; i < D; i++) {
        comparators[i] = new double*[values[i]];
        for (int x = 0; x < values[i]; x++) {
            comparators[i][x] = new double[values[i]];
            comparators[i][x][x] = 0;
            for (int y = 0; y < x; y++) {
                comparators[i][x][y] = comparators[i][y][x] = unif(rng);
            }
        }
    }
}

void model::print() {
    cout << fixed;
    cout << setprecision(2);
    for (int i = 0; i < D; i++) {
        cout << "Comparison Model for Dimension: " << i << endl;
        for (int x = 0; x < dim_domains[i]; x++) {
            for (int y = 0; y < dim_domains[i]; y++) {
                cout << comparators[i][x][y] << " ";
            }
            cout << endl;
        }
    }            
}

void model::create_world() {
    return;
}