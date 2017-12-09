/* 
 * contigsum.hpp
 * Jason Warta
 * CS411 Assignment 3 Exercise A
 * 2017-10-13
 */

#ifndef CONTIGSUM_HPP_INCLUDED
#define CONTIGSUM_HPP_INCLUDED

#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
using std::max;
#include <numeric>
using std::accumulate;

struct ResultSet{
	ResultSet() {}
	ResultSet(int a, int b, int c, int d) :
		GCS(a), 
		greatestPossibleWithFirst(b), 
		greatestPossibleWithLast(c), 
		sum(d)
	{}

	int GCS; //A
	int greatestPossibleWithFirst; //B
	int greatestPossibleWithLast; //C
	int sum; //D

	int maxOfSet() {
		return max<int>({
			GCS,
			greatestPossibleWithFirst,
			greatestPossibleWithLast,
			sum,
			0
		});
	}
};

template<typename RAIter>
ResultSet contigSumRecurse(RAIter first, RAIter last) {
	if(last - first < 2) {
		return ResultSet(
			*first,
			*first,
			*(last-1),
			accumulate(first,last,0)
		);

	} else {
		RAIter mid = first + (last-first)/2;
		ResultSet lhs = contigSumRecurse(first,mid);
		ResultSet rhs = contigSumRecurse(mid,last);

		return ResultSet(
			max<int>({
				lhs.greatestPossibleWithLast+rhs.greatestPossibleWithFirst,
				lhs.GCS,
				rhs.GCS
			}),
			max<int>({
				lhs.greatestPossibleWithFirst,
				lhs.sum + rhs.greatestPossibleWithFirst
			}),
			max<int>({
				lhs.greatestPossibleWithLast + rhs.sum,
				rhs.greatestPossibleWithLast
			}),
			lhs.sum + rhs.sum
		);
	}
}

/* 
 * contigSum
 * input:
 * 		2 Random Access Iterators pointing to the beginning and end of a set
 * output:
 * 		int containing the greatest congiguous sum
 * preconditions:
 * 		iterator to the end of the set must be equal to or after the iterator to the start of the set
 */
template<typename RAIter>
int contigSum(RAIter first, RAIter last){	
	if (last-first) {
		return contigSumRecurse(first,last).maxOfSet();
	}
	return 0;
}

#endif