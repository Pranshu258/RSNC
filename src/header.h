#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <list>

using namespace std;

void create_model(int D, int* values, float *** model);
void print_model(int D, int* values, float *** model);

void create_noisydata(int N, int D, int * values, int **noisydata);
void print_noisydata(int N, int D, int **noisydata);

struct point {
    int id;
    int * features;
};

class data {
    public:
        // Fields
        list<point> DATA;
        int N;
        int D;
        int *DIM_DOMAINS;
        float *** MODEL;
        // Methods
        data (int n, int d, float *** model, int * values);
        void print ();
};