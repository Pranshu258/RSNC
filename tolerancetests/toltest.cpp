#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

int main () {
    // create the score matrix
    double score[50][6];
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 6; j++) {
            score[i][j] = 0;
        }
    }
    // compute the scores
    string line;
    ifstream infile("repr");
    double tolerance;
    for (int t = 0; t < 6; t++) {
        getline(infile, line);
        stringstream ss(line);
        ss >> tolerance;
        //cout << tolerance << endl;
        // read the lines one by one and compute the scores for each data point
        for (int r = 0; r < 100; r++) {
            getline(infile, line);
            stringstream ss1(line);
            int id;
            double ssize = 0;
            while (ss1 >> id) {
                ssize += 1;
            }            
            stringstream ss(line);
            // stream ss has all you need, use it like cin
            double rank = 1;
            while (ss >> id) {
                score[id-1][t] += 1/(ssize*rank);
                rank += 1;
                //cout << id << " ";
            }
            //cout << endl;
        }
    }

    cout << "ID/SCR\t0.0\t0.1\t0.2\t0.3\t0.4\t0.5\n"; 
    for (int i = 0; i < 50; i++) {
        cout << i+1 << "\t";
        for (int j = 0; j < 6; j++) {
            cout << score[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}