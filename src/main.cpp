#include "header.h"

int main() {
    // CREATE THE COMPARISON MODEL
    int D;
    cout << "CREATE THE COMPARISON MODEL" << endl;
    cout << "Enter the number of Dimensions: "; cin >> D;
    int values[D];
    cout << "Enter the number of possible values in each dimension: \n";
    for (int i = 0; i < D; i++) {
        cout << i << ": "; cin >> values[i];
    }
    float **model[D];
    create_model(D, values, model);
    print_model(D, values, model);

    // CREATE THE DATASET
    int N;
    cout << "Enter the number of Samples: "; cin >> N;
    int **noisydata = new int*[N];
    create_noisydata(N, D, values, noisydata);
    print_noisydata(N, D, noisydata);

    // Sort the Dataset on each dimension

    // Find the Skyline Set

    // Find the Representative Skyline Set

    return 0;
}