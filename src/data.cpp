#include "header.h"

data::data (int n, int d, int * values) {
    N = n; D = d;
    for (int i = 0; i < N; i++) {
        point *p = new point;
        p->features = new int[D];
        p->id = i+1;
        DATA.push_back(*p);              
    }
    for (int j = 0; j < D; j++) {
        random_device rd;
        mt19937 rng(rd());    
        uniform_int_distribution<int> uni(0,values[j]-1);
        for (list<point>::iterator p = DATA.begin(); p != DATA.end(); p++) {
            (*p).features[j] = uni(rng);
        }
    }            
}

void data::print () {
    for (list<point>::iterator p = DATA.begin(); p != DATA.end(); p++) {
        cout << (*p).id << ": ";
        for (int j = 0; j < D; j++) {
            cout << j << "_" << (*p).features[j] << " ";
        }
        cout << endl;
    }
}
