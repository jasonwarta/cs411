#include "build.h"

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

bool unusable_bridge(const Bridge & bridge, const vector<Bridge> & bridges){
	return ( bridge_crosses_bridges( bridge, bridges ) || 
			 same_city( bridge, bridges ) );
}

int build(int w, int e, const vector<Bridge> & bridges){
	vector<Bridge> more_bridges = bridges;
	sort(more_bridges.begin(),more_bridges.end(), [](auto &lhs, auto &rhs){
		return lhs[2] > rhs[2];
	});

	int best_bridge = 0;

	for(auto & first_bridge : more_bridges) {
		vector<Bridge> good_bridges(0);
		good_bridges.push_back(first_bridge);

		for(auto & next_bridge : more_bridges) {
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