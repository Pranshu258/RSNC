#include "header.h"

double skyline::jaccard_similarity(list<int> s1, list<int> s2) {
    vector<int> common_points;
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), std::back_inserter(common_points));
    // cout << common_points.size() << " " << s1.size() << " " << s2.size() << endl;
    double d = 1.0*(common_points.size())/(s1.size() + s2.size() - common_points.size());
    return d;
}

void skyline::compute_jaccard_distances() {
    jaccard_distances = new double*[SKYLINE_SET.size()];
    skyline_point_ids = new int[SKYLINE_SET.size()];
    int i = 0;
    for (map<int, list<int> >::iterator s1 = DOMINANCES.begin(); s1 != DOMINANCES.end(); s1++) {
        jaccard_distances[i] = new double[SKYLINE_SET.size()];
        skyline_point_ids[i] = s1->first;
        jaccard_distances[i][i] = 0;
        int j = 0;
        for (map<int, list<int> >::iterator s2 = DOMINANCES.begin(); s2 != s1; s2++) {
            jaccard_distances[i][j] = jaccard_distances[j][i] = 1 - jaccard_similarity(s1->second, s2->second);
            j+=1;
        }
        i+=1;
    }
}

void skyline::print_jaccard_distances() {
    cout << "JACCARD DISTANCE TABLE:" << endl;
    for (int i = 0; i < SKYLINE_SET.size(); i++) {
        cout << "\t" << skyline_point_ids[i];
    }
    cout << endl;
    for (int i = 0; i < SKYLINE_SET.size(); i++) {
        cout << skyline_point_ids[i] << ":";
        for (int j = 0; j < SKYLINE_SET.size(); j++) {
            cout << "\t" << jaccard_distances[i][j];
        }
        cout << endl;
    }
}