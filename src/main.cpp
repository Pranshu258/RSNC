#include "header.h"

int main() {
    // Create a Dataset
    int N, D;
    cout << "Enter the number of Samples: "; cin >> N;
    cout << "Enter the number of Dimensions: "; cin >> D;
    int values[D];
    cout << "Enter the number of possible values in each dimension: \n";
    for (int i = 0; i < D; i++) {
        cout << i << ": "; cin >> values[i];
    }
    // Create the Comparison Model
    float **model[N];
    create_model(N, D, values, model);
    print_model(model);
    

    // Sort the Dataset on each dimension

    // Find the Skyline Set

    // Find the Representative Skyline Set

    return 0;
}