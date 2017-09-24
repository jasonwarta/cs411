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
	for ( auto & item : bridges )
		print_bridge( item );
	cout << endl;
}

bool bridges_cross(const Bridge & lhs, const Bridge & rhs){
	return ( lhs[0] < rhs[0] && lhs[1] > rhs[1] ) || 
		   ( lhs[0] > rhs[0] && lhs[1] < rhs[1] );
}

bool bridge_crosses_bridges(const Bridge & bridge, const vector<Bridge> & bridges){
	for ( auto & bridge_iter : bridges )
		if ( bridges_cross( bridge, bridge_iter) ) 
			return true;
	return false;
}

bool same_city(const Bridge & lhs, const Bridge & rhs) {
	return lhs[0] == rhs[0] || lhs[1] == rhs[1];
}

bool same_city(const Bridge & bridge, const vector<Bridge> & bridges){
	for ( auto & bridge_iter : bridges )
		if ( same_city( bridge, bridge_iter ) ) 
			return true;
	return false;
}

int build(int w, int e, const vector<Bridge> & bridges){
	int best_bridge = 0;

	for(auto & first_bridge : bridges) {
		vector<Bridge> good_bridges(0);
		good_bridges.push_back(first_bridge);

		for(auto & next_bridge : bridges) {
			if ( bridge_crosses_bridges( next_bridge, good_bridges ) || 
				 same_city( next_bridge, good_bridges ) ) 
				continue;
			good_bridges.push_back( next_bridge );
		}

		int current_total = 0;
		for ( auto bridge : good_bridges ) {
			current_total += bridge[2];
		}
		best_bridge = max(best_bridge,current_total);
	}
	return best_bridge;
}