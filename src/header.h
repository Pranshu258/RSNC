#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;
using namespace std::chrono;

struct point {
    int id;
    int * features;
    double timestamp;
};


// This class defines the comparison model for possible values for each dimension
class model {
    public:
        // Fields
        int D;
        double e;
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
        vector<point> SKYLINE_SET;
        int * skyline_point_ids;
        double ** jaccard_distances;
        map<int, list<int> > DOMINANCES;
        int N;
        int D;
        skyline (int N, int D, list<point> data);
        bool operator () (const point &p1, const point &p2);
        void finder();
        void find_dominance_sets();
        void print_dominance_sets();
        double jaccard_similarity(list<int> set1, list<int> set2);
        void compute_jaccard_distances();
        void print_jaccard_distances();
        void represent();
        
};

void generate_modelfile(int D, int* dim_domains);
void generate_datafile (int N, int D, int * dim_domains);