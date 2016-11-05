#include "header.h"

skyline::skyline (int n, int d, list<point> data) {
    N = n;
    D = d;
    DATA = data;
}

bool skyline::operator () (const point &p1, const point &p2) {
	// find the entropy of both the functions
	double e1 = 0, e2 = 0;
	for (int k = 0; k < D; k++) {
		e1 += log(p1.features[k] + 1);
		e2 += log(p2.features[k] + 1);
	}
	//cout << e1 << " " << e2 << endl;
	return e1 < e2;    
}

void skyline::finder () {
    // Sort the data by entropy
    DATA.sort(*this);
    int win_size = 3;
    bool *is_skyline = new bool[N];
	for (int i = 0; i < N; i++) {
		is_skyline[i] = false;
	}
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

	// BLOCK NESTED LOOP ALGORITHM FOR SKYLINES
	//////////////////////////////////////////////////////////////////////////////
	// NOW WE CAN START FINDING THE SKYLINES
	int comparisons = 0;;
	list<point> skyline_window;
	while (!DATA.empty()) {
		list<point> temp_data;

		for (list<point>::iterator p = DATA.begin(); p != DATA.end(); p++) {

			bool not_skyline = false;
			list<point>::iterator swp = skyline_window.begin();
			while (swp != skyline_window.end()) {
				int equalorworse = 0, worse = 0;
				int equalorbetter = 0, better = 0;
				for (int k = 0; k < D; k++) {
					if ((*p).features[k] > (*swp).features[k]) {
						worse += 1;
					} else if ((*p).features[k] == (*swp).features[k]) {
						equalorworse += 1;
						equalorbetter += 1;
					} else if ((*p).features[k] < (*swp).features[k]) {
						better += 1;
					}
				}
				if (equalorworse + worse == D && worse > 0) {
					not_skyline = true;
				}
				if (equalorbetter + better == D && better > 0) {
					// remove swp from the window
					// cout << "Removed " << (*swp).id << " from Skyline window, dominated by: " << (*p).id << endl;
					swp = skyline_window.erase(swp);
					comparisons += 1;
					continue;
				}
				comparisons += 1; 
				swp++;
			}   
			// if not_skyline is still false, try to insert this point in the skyline window
			if (!not_skyline) {
				if (skyline_window.size() < win_size) {
					// get the timestamp and push in the skyline data
					(*p).timestamp = comparisons;
					skyline_window.push_back(*p);
					// cout << "Inserted " << (*p).id << " in Skyline window. Time: " << (*p).timestamp << endl;
				}
				else {
					// get the timestamp and put in the temp data
					(*p).timestamp = comparisons;
					temp_data.push_back(*p);
					// cout << "Inserted " << (*p).id << " in temp_data. Time: " << (*p).timestamp << endl;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////

		// mark the skyline points
		list<point>::iterator swp = skyline_window.begin();
		while (swp != skyline_window.end()) {
			// cout << "Size of Skyline Window: " << skyline_window.size() << endl;
			if (skyline_window.size() > 0) {
				if ((*swp).timestamp < (temp_data.front()).timestamp || temp_data.size() == 0) {
					// cout << "Removing " << swp->id << " from window as valid skyline" << endl;
					if (swp->id <= N) {
						is_skyline[(swp->id)-1] = true;
						swp = skyline_window.erase(swp);
						continue;
					} else {
						cout << "Something went wrong" << endl;
					}
				} else {
					break;
				}
			} else {
				break;
			}
			swp++;
		}		

		// cout << "-------------------------------------------" << endl;

		DATA = temp_data;
		temp_data.clear();
	}


	/////////////////////////////////////////////////////////////////////////////

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	cout << "Skyline Points: " << endl;
	int printed = 0;
	for (int i = 0; i < N; i++) {
		if (is_skyline[i]) {
			cout << i+1 << "\t";
			printed += 1;
			if (printed % 10 == 0)
				cout << endl;
		}
	}
	cout << endl;
	cout << "Number of skyline points: " << printed << endl;
	cout << "Number of comparisons: " << comparisons << endl;
	cout << "Time taken: " << time_span.count() << " seconds" << endl;

    return;
}