#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <vector>
#include <stdio.h>
#include <chrono>

class SortControl{
public:
	SortControl() = default;
	bool isSorted(std::vector<int>& array) const;
	void populateArray (std::vector<int>& array, int elements);
private:
};

#endif