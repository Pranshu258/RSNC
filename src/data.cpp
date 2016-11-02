#include "header.h"

void create_noisydata(int N, int D, int * values, int **noisydata) {
    for (int i = 0; i < N; i++) {
        noisydata[i] = new int[D];
    }
    for (int j = 0; j < D; j++) {
        random_device rd;
        mt19937 rng(rd());    
        uniform_int_distribution<int> uni(0,values[j]-1);
        for (int i = 0; i < N; i++) {
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