/* 
 * build.h
 * Jason Warta
 * CS411 Homework 5
 * 2017-11-20
 */

#ifndef BUILD_H_INCLUDED
#define BUILD_H_INCLUDED

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;

#include <algorithm>
using std::sort;

#include <cmath>
using std::max;

using Bridge = vector<int>;
using Tolls = vector<vector<int>>;

int build(int w, int e, const std::vector<Bridge> & bridges);

class BridgeBuilder {
public:
	BridgeBuilder(int w, int e, const vector<Bridge> & bridges);
	int buildBridges(int w, int e);
	void printTolls();

private:
	Tolls _tolls;
	vector<Bridge> _bridges;
};

#endif