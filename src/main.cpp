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

    // CREATE THE DATASET OBJECT
    int N;
    cout << "Enter the number of Samples: "; cin >> N;
    data DATA(N, D, model, values);
    DATA.print();

    // Sort the Dataset on each dimension
    

    // Find the Skyline Set

    // Find the Representative Skyline Set

    return 0;
}