#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct point {
    int id;
    int * features;
};

class model {
    public:
        // Fields
        int D;
        int oracle_state;
        int * dim_domains;
        double *** comparators;
        vector<vector<int> > world;
        // Methods
        model(int d, int* dim_domains);
        bool operator () (const int &x, const int &y);
        void create_world();
        void print_world();
        void print();
};

class data {
    public:
        // Fields
        list<point> DATA;
        int N;
        int D;
        // Methods
        data (int n, int d, int * dim_domains);
        void print ();
};