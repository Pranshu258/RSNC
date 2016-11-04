#include "header.h"

int main() {
    // CREATE THE COMPARISON MODEL
    int D;
    cout << "CREATE THE COMPARISON MODEL" << endl;
    cout << "Enter the number of Dimensions: "; cin >> D;
    int dim_domains[D];
    cout << "Enter the number of possible values in each dimension: \n";
    for (int i = 0; i < D; i++) {
        cout << i << ": "; cin >> dim_domains[i];
    }
    model MODEL(D, dim_domains);
    MODEL.print();
    MODEL.create_world();
    MODEL.print_world();

    // CREATE THE DATASET OBJECT
    int N;
    cout << "Enter the number of Samples: "; cin >> N;
    data DATA(N, D, dim_domains);
    DATA.print();

    // CREATE AN INSTANCE OF CONCRETE DATA (POSSIBLE WORLD WITH ERROR)
    

    // Find the Skyline Set

    // Find the Representative Skyline Set

    return 0;
}