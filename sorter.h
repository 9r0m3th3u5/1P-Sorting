/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <string>
#include <cstddef>
#include <vector>

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead put them at the beginning of class or function definitions
 * (as demonstrated below).
 *
 * For more details, see the commentary at the top of
 *   tests/header-sans-using-namespace.h
 * in this project repo.
 */

template <class T>
void sorter(std::vector<T> &items, std::size_t k) {  
	using namespace std;
	// write your solution for k-way merge sort below	
	if(items.size() == 1) return items;

	size_t splitSize = items.size() / k;
	size_t overflow = items.size() - splitSize * k;
	vector<T>* arrays = new vector<T>[k];
	unsigned count = 0;
	for(unsigned i = 0; i < overflow; i++) {
		arrays[i] = new vector<T>(splitSize + 1);
		for(unsigned j = 0; j < splitSize + 1; j++) {
			arrays[i].push(items.get(count));
			count++;
		}
	}
	for(unsigned i = overflow; i < k; i++) {
		arrays[i] = new vector<T>(splitSize);
		for(unsigned j = 0; j < splitSize; j++) {
			arrays[i].push(items.get(count));
			count++;
		}
	}
	for(unsigned i = 0; i < k; i++) {
		sorter(arrays[i], arrays[i].size());
	}
}
#endif
