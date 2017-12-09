// iterative_merge_sort.cpp
// Glenn G. Chappell
// 13 Oct 2005
//
// For CS 311
// Iterative Merge Sort Using Random-Access Iterators
// 
// 
// Modified by Jason Warta to add a counter for the number of inversions
// CS411 Assignment 3 Exercise B
// Function definitions were changed to return counters
// counters added at lines 49, 56, 71, 97, 110, 116


#include <iostream>
using std::cout;
using std::endl;

#include <vector>     // For std::vector
#include <iterator>   // For std::distance, std::iterator_traits
#include <cstdlib>    // For std::size_t
#include <algorithm>  // For std::copy

// stableMerge
// Merge two halves of a sequence, each sorted,
//  into a single sorted sequence in the same location.
//  Merge is done in a stable manner.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, middle) and [middle, last) are valid ranges,
//      each sorted by <.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner).
template <typename FDIter>
std::size_t stableMerge(FDIter first, FDIter middle, FDIter last)
{
    typedef typename std::iterator_traits<FDIter>::value_type ValueType;
    typedef typename std::vector<ValueType> BufferType;

    BufferType buffer(std::distance(first, last));
    FDIter in1 = first;
    FDIter in2 = middle;
    typename BufferType::iterator out = buffer.begin();
                          // Current write location in buffer

    std::size_t counter = 0;

    // Merge two sorted lists into a single list in buff.
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1) { // Must do comparison this way, to be stable.
            *out++ = *in2++;
            counter+= (middle-in1);
        }
        else {
            *out++ = *in1++;
        }
    }

    // Copy remainder of original sequence to buffer.
    // Only one of the following two copy calls will do anything.
    std::copy(in1, middle, out);
    std::copy(in2, last, out);

    // Copy buffer contents back to original sequence location.
    std::copy(buffer.begin(), buffer.end(), first);

    return counter;
}


// iterativeMergeSort
// Sorts a sequence, using iterative Merge Sort.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     operator< is a total order on the value type of RAIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner).
// NOTE:
//     We could make this iterative version of Merge Sort work with forward
//     iterators. However, the tests (lo + partitionSize < last) and
//     (last < hi) would become more complicated. Since forward iterators
//     are not required to have the "<" operator, we would either have to
//     check for equality  with "last" each time we increment an iterator,
//     or else use std::advance, but also keep track of how far along we
//     are using numeric variables.
template <typename RAIter>
std::size_t iterativeMergeSort(RAIter first, RAIter last)
{
    std::size_t size = last - first;
    std::size_t counter = 0;

    std::size_t partitionSize = 1;  // Size of two sequences to be merged
    while (partitionSize < size)
    {
        RAIter lo = first;  // start of 1st sequence to be merged
        while (lo + partitionSize < last)
        {
            RAIter hi = lo + partitionSize * 2;
                // just-past end of 2nd sequence to be merged
            if (last < hi) {
              hi = last;
            }
            counter += stableMerge(lo, lo+partitionSize, hi);

            lo = hi;
        }
        partitionSize *= 2;
    }
    return counter;
}