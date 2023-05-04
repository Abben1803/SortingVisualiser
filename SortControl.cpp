#include "SortControl.h"


// checking if the array is sorted
bool SortControl::isSorted(std::vector<int>& array) const {
	for (auto i = 0; i < array.size() - 1; i++) {
		if (array[i] == array[i + 1]) {
			return false;
		}
	}
	return true;
}

void SortControl::populateArray(std::vector<int>& array, int elements) {
	std::srand(std::time(0));
	for (int i = 0; i < elements; i++) {
		int random_number = std::rand() % 500;
		array.push_back(random_number);
	}
}