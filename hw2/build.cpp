#include "build.h"

#include <iostream>
#include <algorithm>
#include <cmath>

using std::sort;
using std::max;
using std::cout;
using std::endl;
using std::for_each;

void print_bridge(const Bridge & bridge){
	cout << bridge[0] << "," << bridge[1] << "," << bridge[2] << endl;
}

void print_bridges(const vector<Bridge> & bridges){
	for (auto i = bridges.begin(); i != bridges.end(); ++i) {
		print_bridge((*i));
	}
	cout << endl;
}

bool bridges_cross(const Bridge & lhs, const Bridge & rhs){
	return ( lhs[0] < rhs[0] &&
			 lhs[1] > rhs[1] ) || 
		   ( lhs[0] > rhs[0] &&
			 lhs[1] < rhs[1] );
}

bool bridge_crosses_bridges(const Bridge & bridge, const vector<Bridge> & bridges){
	for ( auto i = bridges.begin(); i != bridges.end(); ++i ) {
		if ( bridges_cross( bridge, (*i) ) ) return true;
	}
	return false;
}

bool same_city(const Bridge & lhs, const Bridge & rhs) {
	return lhs[0] == rhs[0] || lhs[1] == rhs[1];
}

bool same_city(const Bridge & bridge, const vector<Bridge> & bridges){
	for ( auto i = bridges.begin(); i != bridges.end(); ++i ) {
		if ( same_city(bridge, (*i) ) ) return true;
	}
	return false;
}

int build(int w, int e, const vector<Bridge> & bridges){
	int best_bridge = 0;
	for ( auto i = 0; i < bridges.size(); ++i ) {
		vector<Bridge> good_bridges(0);
		good_bridges.push_back(bridges[i]);
		for ( auto j = 0; j < bridges.size(); ++j ) {
			if ( bridge_crosses_bridges( bridges[j], good_bridges ) ) {
				continue;
			}
			if ( same_city( bridges[j], good_bridges ) ) {
				continue;
			}
			good_bridges.push_back(bridges[j]);
		}

		int current_total = 0;
		for ( auto bridge : good_bridges ) {
			current_total += bridge[2];
		}
		best_bridge = max(best_bridge,current_total);
	}
	return best_bridge;
}