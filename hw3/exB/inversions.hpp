#ifndef INVERSIONS_HPP_INCLUDED
#define INVERSIONS_HPP_INCLUDED

#include "merge_sort.hpp"

#include <cstdio>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::sort;

template<typename RAIter>
size_t inversions(RAIter first, RAIter last){
	// int counter = 0;
	// sort(first,last,[&counter](auto &a, auto&b){
	// 	if(a < b) counter++;
	// 	return a<b;
	// });
	
	// int counter =  iterativeMergeSort(first,last);

	// cout << counter << endl;
	return iterativeMergeSort(first,last);
}

#endif