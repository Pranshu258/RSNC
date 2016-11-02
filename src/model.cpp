#include "header.h"

void create_model(int D, int* values, float *** model) {
    // Create the Random Number Generator Object
    mt19937_64 rng;
    uint64_t timeSeed = chrono::high_resolution_clock::now().time_since_epoch().count();
    seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);
    for (int i = 0; i < D; i++) {
        model[i] = new float*[values[i]];
        for (int x = 0; x < values[i]; x++) {
            model[i][x] = new float[values[i]];
            model[i][x][x] = 0;
            for (int y = 0; y < x; y++) {
                model[i][x][y] = model[i][y][x] = unif(rng);
            }
        }
    }
}

void print_model(int D, int* values, float *** model) {
    cout << fixed;
    cout << setprecision(2);
    for (int i = 0; i < D; i++) {
        cout << "Comparison Model for Dimension: " << i << endl;
        for (int x = 0; x < values[i]; x++) {
            for (int y = 0; y < values[i]; y++) {
                cout << model[i][x][y] << " ";
            }
            cout << endl;
        }
    }
}