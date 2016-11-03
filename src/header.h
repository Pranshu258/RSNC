#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <list>

using namespace std;

void create_model(int D, int* values, double *** model);
void print_model(int D, int* values, double *** model);

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
        // Methods
        model(int d, int* values);
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