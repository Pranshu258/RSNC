#include "header.h"

// This method finds the dominance set of each skyline
void skyline::find_dominance_sets () {
	for (vector<point>::iterator s = SKYLINE_SET.begin(); s != SKYLINE_SET.end(); s++) {
        pair<int, list<int> > PAIR;
        PAIR.first = s->id;
        // cout << s->id << ": ";
		for (list<point>::iterator p = DATA.begin(); p != DATA.end(); p++) {
            // check if s dominates p
            int better = 0;
            int equalorbetter = 0;
            for (int k = 0; k < D; k++) {
                if ((*p).features[k] > (*s).features[k])
                    better += 1;
                if ((*p).features[k] >= (*s).features[k])
                    equalorbetter += 1;
            }
            // cout << better << " " << equalorbetter << endl;
            if (equalorbetter == D && better > 0) {
                // insert p->id in the dominance set of s
                //cout << p->id << " ";
                PAIR.second.push_back(p->id);
            }        
        }
        DOMINANCES.insert(PAIR);
	}
}

// This method prints the dominance set of each skyline
void skyline::print_dominance_sets() {
    cout << "DOMINANCE SETS:" << endl;
    for (map<int, list<int> >::iterator it = DOMINANCES.begin(); it != DOMINANCES.end(); it++) {
        cout << it->first << ": ";
        list<int> dominated = it->second;
        for (list<int>::iterator p = dominated.begin(); p != dominated.end(); p++) {
            cout << *p << " ";
        }
        cout << endl;
    }
}