#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <list>

using namespace std;

struct point {
    int id;
    int * features;
};

class model {
    public:
        // Fields
        int D;
        int * dim_domains;
        double *** comparators;
        double ** world;
        // Methods
        model(int d, int* values);
        void create_world();
        void print();
};

class data {
    public:
        // Fields
        list<point> DATA;
        int N;
        int D;
        int comparing_dim;
        // Methods
        data (int n, int d, int * values);
        void print ();
};