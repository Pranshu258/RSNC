#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

void create_model(int N, int D, int* values, float *** model);
void print_model(int D, int* values, float *** model);
