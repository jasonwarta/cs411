#ifndef BUILD_H
#define BUILD_H_INCLUDED

#include <vector>

using Bridge = std::vector<int>;

int build(int w, int e, const std::vector<Bridge> & bridges);

#endif