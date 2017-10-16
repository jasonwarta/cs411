#ifndef BUILD_H
#define BUILD_H_INCLUDED

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::for_each;
using std::sort;

#include <cmath>
using std::max;

using Bridge = std::vector<int>;

void print_bridge(const Bridge & bridge);
void print_bridges(const vector<Bridge> & bridges);

bool bridges_cross(const Bridge & lhs, const Bridge & rhs);
bool bridge_crosses_bridges(const Bridge & bridge, const vector<Bridge> & bridges);

bool same_city(const Bridge & lhs, const Bridge & rhs);
bool same_city(const Bridge & bridge, const vector<Bridge> & bridges);

int build_bridges(auto & position, const std::vector<Bridge> & bridges, vector<Bridge> good_bridges);

int build(int w, int e, const std::vector<Bridge> & bridges);

#endif