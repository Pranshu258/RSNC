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
    model MODEL(D, values);
    MODEL.print();

    // CREATE THE DATASET OBJECT
    int N;
    cout << "Enter the number of Samples: "; cin >> N;
    data DATA(N, D, values);
    DATA.print();

    // CREATE AN INSTANCE OF CONCRETE DATA (POSSIBLE WORLD WITH ERROR)
    

    // Find the Skyline Set

    // Find the Representative Skyline Set

    return 0;
}