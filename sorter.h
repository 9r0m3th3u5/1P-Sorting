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
	size_t overflow = items.size() % k;
	vector<T>* arrays = new vector<T>[k];
	for(unsigned i = 0; i < k; i++) {
		arrays + i = new vector<T>();
	}
	for(unsigned i = 0; i < items.size(); i++) {
		arrays[i % k].push_back(items.at(0));
		items.erase(0);
	}

	for(unsigned i = 0; i < k; i++) {
		sorter(arrays[i], arrays[i].size());
	}

	unsigned min = 0;
	for(unsigned i = 0; i < items.size(); i++) {
		for(unsigned j = 0; j < k; j++) {
			if(!arrays[j].empty() && arrays[j].at(0) < arrays[min].at(0)) min = j;
		}
		items.push_back(arrays[min].at(0));
		arrays[min].erase(0);
	}
}
#endif
