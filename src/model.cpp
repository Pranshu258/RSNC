#include "header.h"

model::model(int d, int* dd) {
    D = d;
    dim_domains = dd;
    comparators = new double**[D];

    // Create the Random Number Generator Object
    mt19937_64 rng;
    uint64_t timeSeed = chrono::high_resolution_clock::now().time_since_epoch().count();
    seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);
    for (int i = 0; i < D; i++) {
        comparators[i] = new double*[dim_domains[i]];
        for (int x = 0; x < dim_domains[i]; x++) {
            comparators[i][x] = new double[dim_domains[i]];
            comparators[i][x][x] = 0;
            for (int y = 0; y < x; y++) {
                comparators[i][x][y] = unif(rng);
                comparators[i][y][x] = 1 - comparators[i][x][y];
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


// IMPLEMENT NOISY COMPARISON HERE ///////////////////////////////////////////
bool model::operator () (const int &x, const int &y) { 
    // Can use the member variables of the model object here :) GREAT :D
    double e = 0.1; // The error parameter for noisy comparison
    double p = comparators[oracle_state][x][y];
    int t = dim_domains[oracle_state];
    t = t*log2(t)/e;
    random_device rd;
    mt19937 gen(rd());
    if (p < 0.5)
        p = p + e;
    else
        p = p - e;
    discrete_distribution<> distrib({1-p, p});
    int comp = 0;
    for (int i = 0; i < t; i++) {
        comp += distrib(gen);
    }
    return comp > t/2;
}
/////////////////////////////////////////////////////////////////////////////


void model::create_world() {
    for (int i = 0; i < D; i++) {
        list<int> L;
        for (int j = 0; j < dim_domains[i]; j++) {
            L.push_back(j);
        }
        oracle_state = i;
        L.sort(*this);
        world.push_back(L);
    }
}

void model::print_world() {
    cout << "The World Instance: " << endl;
    for (list<list<int> >::iterator L = world.begin(); L != world.end(); L++) {
        auto dim = *L;
        for (list<int>::iterator d = dim.begin(); d != dim.end(); d++) {
            cout << *d << " ";
        }
        cout << endl;
    }
}