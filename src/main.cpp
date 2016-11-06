#include "header.h"

int main() {
    // CREATE THE COMPARISON MODEL
    int D; // D is the number of dimensions
    cout << "CREATE THE COMPARISON MODEL" << endl;
    cout << "Enter the number of Dimensions: "; cin >> D;
    int dim_domains[D]; // This array stores the number of possible values for each dimension
    cout << "Enter the number of possible values in each dimension: \n";
    for (int i = 0; i < D; i++) {
        cout << i << ": "; cin >> dim_domains[i];
    }
    model MODEL(D, dim_domains); // create the comparison model for the noisy values
    MODEL.print();
    MODEL.create_world();  // create a possible world with a discrete ordering on the noiy values for each dimension
    MODEL.print_world();

    // CREATE THE DATASET OBJECT
    int N;
    cout << "Enter the number of Samples: "; cin >> N;
    data DATA(N, D, dim_domains);       // create a dataset with attributes having noisy values 
    DATA.print(0);

    // CREATE AN INSTANCE OF CONCRETE DATA (POSSIBLE WORLD WITH ERROR)
    DATA.label_data(MODEL.world);
    cout << "Labeled Data: " << endl;
    DATA.print(1);

    // FIND THE SKYLINE
    skyline SKYLINES(N, D, DATA.DATA);
    SKYLINES.finder();
    // Find the Representative Skyline Set

    return 0;
}