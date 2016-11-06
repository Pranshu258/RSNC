#include "header.h"

// Algorithm:
// Choose initial representative skyline: Preferably one with biggest dominance set
// Iterate:
//     Choose next representative q such that minimum Jaccard distance of q to any p in A is maximized
//     break ties using domination score

void skyline::represent() {
    map<int, list<int> > S = DOMINANCES;
    map<int, list<int> > A;
    cout << "SKYLINES IN REPRESENTATIVE ORDER:" << endl;
    // Pick the skyline with highest dominance set
    int max = 0;
    map<int, list<int> >::iterator a;
    for (map<int, list<int> >::iterator it = S.begin(); it != S.end(); it++) {
        list<int> dominated = it->second;
        if (max < dominated.size()) {
            a = it;
            max = dominated.size();
        }
    }
    cout << a->first << " ";
    A.insert(*a);
    S.erase(a);
    // Iterate
    while (S.size()) {
        // find the s in S with maximum min_d from A
        double max = -1;
        map<int, list<int> >::iterator next_s;
        for (map<int, list<int> >::iterator s = S.begin(); s != S.end(); s++) {
            int x = distance(skyline_point_ids, find(skyline_point_ids, skyline_point_ids + SKYLINE_SET.size(), s->first));
            // find the minimum jaccard distance of s from A
            double min_d = 2.0;
            for (map<int, list<int> >::iterator a = A.begin(); a != A.end(); a++) {
                int y = distance(skyline_point_ids, find(skyline_point_ids, skyline_point_ids + SKYLINE_SET.size(), a->first));
                double d = jaccard_distances[x][y];
                if (d < min_d) {
                    min_d = d;
                }
            }
            if (max < min_d || (max == min_d && (s->second).size() > (next_s->second).size())) {
                next_s = s;
                max = min_d;
            }
        }
        cout << next_s->first << " ";
        A.insert(*next_s);
        S.erase(next_s);
    }
    cout << endl;
    return;
}