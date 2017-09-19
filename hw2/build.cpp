#include "build.h"

#include <iostream>
using std::cout;
using std::endl;

int build(int w, int e, const std::vector<Bridge> & bridges) {
	if (!w || !e || !bridges.size()) return 0;
	
	return bridges.front()[2] + build(w, e, std::vector<Bridge>(bridges.begin()+1,bridges.end()));

	return 0;
}