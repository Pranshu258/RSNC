#include "header.h"

int main(int argc, char *argv[]) {

    if (argc != 3) {
		cout << "Usage: ./main new_model new_data" << endl;
		exit(0);
	}
    string new_model = argv[1];
    string new_data = argv[2];
    // cout << (new_model == "t") << " " << (new_data == "t") << endl;

    // CREATE THE COMPARISON MODEL
    int D; // D is the number of dimensions
    //cout << "CREATE THE COMPARISON MODEL" << endl;
    //cout << "Enter the number of Dimensions: "; 
    ifstream dims_file("input/dims");
    ifstream samples_file("input/samples");

    dims_file >> D;
    int dim_domains[D]; // This array stores the number of possible values for each dimension
    //cout << "Enter the number of possible values in each dimension: \n";
    for (int i = 0; i < D; i++) {
        // cout << i << ": "; 
        dims_file >> dim_domains[i];
    }

    if (new_model == "t") {
        generate_modelfile(D, dim_domains); // create the comparison model for the noisy values
    }
     
    model MODEL(D, dim_domains); 
    MODEL.create_world();  // create a possible world with a discrete ordering on the noiy values for each dimension
    //MODEL.print_world();

    // CREATE THE DATASET OBJECT
    int N;
    // cout << "Enter the number of Samples: "; 
    samples_file >> N;

    if (new_data == "t" || new_model == "t") {
        generate_datafile(N, D, dim_domains);          // create a dataset with attributes having noisy values
    }
    
    data DATA(N, D, dim_domains);        
    //DATA.print(1);

    // CREATE AN INSTANCE OF CONCRETE DATA (POSSIBLE WORLD WITH ERROR)
    DATA.label_data(MODEL.world);
    //cout << "Labeled Data: " << endl;
    //DATA.print(1);

    // FIND THE SKYLINE
    skyline SKYLINES(N, D, DATA.DATA);
    SKYLINES.finder();
    
    SKYLINES.find_dominance_sets();
    //SKYLINES.print_dominance_sets();

    SKYLINES.compute_jaccard_distances();
    //SKYLINES.print_jaccard_distances();

    SKYLINES.represent();

    return 0;
}