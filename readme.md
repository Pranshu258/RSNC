# Representative Skylines with Noisy Comparisons
### Pranshu Gupta

The project involves the implementation of the following modules:
* Sorting the dataset using noisy comparisons on each dimension
* Using the sorted data to find representative skylines

## Module 1: Sorting with Noisy Comparisons
We sort the attributes of each dimension by repetively comparing each pair with the help of the 
noisy comparison model and then taking the majority vote.
The indices of the values so sorted can be treated as their symbolic values which can be used to find the skylines.

## Module 2: Finding Skylines
We use the SFS algorithm to find out the skylines of the given dataset. The symbolic values of the attributes are assumed 
to be the true values. 

## Module 3: Finding Representative Skylines
For representative skylines we find the jaccard distances between the skyline points and then compute the 
distance based represenative order of all the skyline points.

## Compilation
g++ -std=c++11 src/*.cpp -o bin/rsnc

## How to run
* Prepare the Input files
    - input/dims : write the number of dimensions in the first line followed by D lines such that i'th next line has the domain size of i'th dimension
    - input/samples : write the number of samples in the data
    - input/tolerance : the error tolerance of comparison operator. Choose 0 for best results.
    - input/data : D lines, line i has the i'th dimension attribute value for all the items in the data sepearted by spaces
    - input/model : D matrices, matrix i defining the comparison model for i'th dimension. matrix\[i\][p,q] will contain the probability of p dominating q in dimension i. 
* Run the program
    - If you already have created all the input files then issue the following command
        - `bin/main f f`
    - If you have only created the input files for dims, samples and tolerance and want the program to generate the data and model files for you, issue the following command.
        - `bin/main t t`
    - If you have created the input files for dims, samples tolerance and model and want the program to generate the data file for you, issue the following command
        - `bin/main f t`
    - If you have created the input files for dims, samples tolerance and data and want the program to generate the model file for you, issue the following command
        - `bin/main t f`
    - The program will print the ids of the skyline points in their representative order, along with the number of Skylines and the total time spent in doing the computations.
* Please note that the attribute values in the data file must agree with the number of dimensions and the domain size of each dimension described in the corresponding input files 
    

## References
* U. Feige, P. Raghavan, D. Peleg, and E. Upfal. Computing with noisy information. SIAM J. Comput., 23(5):1001{1018, 1994
* Benoit Groz and Tova Milo. Skyline Queries with Noisy Comparisons. HAL Id: hal-01146568 https://hal.inria.fr/hal-01146568, 2015
* George Valkanas, Apostolos N. Papadopoulos and Dimitrios Gunopulos SkyDiver: A Framework for Skyline Diversification
