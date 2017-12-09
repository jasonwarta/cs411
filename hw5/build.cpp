/* 
 * build.cpp
 * Jason Warta
 * CS411 Homework 5
 * 2017-11-20
 */

#include "build.h"

BridgeBuilder::BridgeBuilder(int w, int e, const vector<Bridge> & bridges){
	_bridges = bridges;
	sort(_bridges.begin(),_bridges.end(), [](auto &lhs, auto &rhs){
		return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
	});

	_tolls = Tolls(w+1, vector<int>(e+1, -1));
}

int BridgeBuilder::buildBridges(int w, int e){
	if(_tolls[w][e] != -1) {
		return _tolls[w][e];
	}

	int toll = 0;
	for(auto & bridge : _bridges) {
		if(bridge[0] < w && bridge[1] < e) {
			toll = max(
				buildBridges(bridge[0],bridge[1]) + bridge[2],
				toll
			);
		}
	}

	_tolls[w][e] = toll;
	return toll;
}

void BridgeBuilder::printTolls(){
	for(int i = 0; i < _tolls.size(); i++) {
		for(int j = 0; j < _tolls[0].size(); j++) {
			cout << setfill(' ') << setw(3) << _tolls[i][j] << "|";
		}
		cout << endl;
	}
}

int build(int w, int e, const vector<Bridge> & bridges){
	BridgeBuilder bridgeBuilder(w,e,bridges);
	return bridgeBuilder.buildBridges(w,e);;
}