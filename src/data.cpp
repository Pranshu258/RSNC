#include "header.h"

void create_noisydata(int N, int D, int * values, int **noisydata) {
    random_device rd;
    mt19937 rng(rd());    
    uniform_int_distribution<int> uni(0,20);
    // for (int i = 0; i < D; i++) {
    //     gen[i] = uni(0,values[i]);
    // }
    for (int i = 0; i < N; i++) {
        noisydata[i] = new int[D];
        for (int j = 0; j < D; j++) {
            noisydata[i][j] = uni(rng);
        }
    }
}

void print_noisydata(int N, int D, int **noisydata) {
    for (int i = 0; i < N; i++) {
        cout << i+1 << ": ";
        for (int j = 0; j < D; j++) {
            cout << noisydata[i][j] << " ";
        }
        cout << endl;
    }
}