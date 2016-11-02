#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <list>

using namespace std;

void create_model(int D, int* values, float *** model);
void print_model(int D, int* values, float *** model);

struct noisypoint {
    int* features;
    int index;
};

struct point {
    int* attributes;
    int index;
};

void create_noisydata(int N, int D, int * values, int **noisydata);
void print_noisydata(int N, int D, int **noisydata);