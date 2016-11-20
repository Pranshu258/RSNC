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

## References
* U. Feige, P. Raghavan, D. Peleg, and E. Upfal. Computing with noisy information. SIAM J. Comput., 23(5):1001{1018, 1994
* Benoit Groz and Tova Milo. Skyline Queries with Noisy Comparisons. HAL Id: hal-01146568 https://hal.inria.fr/hal-01146568, 2015
* George Valkanas, Apostolos N. Papadopoulos and Dimitrios Gunopulos SkyDiver: A Framework for Skyline Diversification
