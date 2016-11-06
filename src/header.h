#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace std::chrono;

struct point {
    int id;
    int * features;
    double timestamp;
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
        void label_data(vector<vector<int> > world);
        void print (int mode);
};

class skyline {
    public:
        list<point> DATA; 
        int N;
        int D;
        bool *is_skyline;
        bool operator () (const point &p1, const point &p2);
        void finder();
        skyline (int N, int D, list<point> data);
};