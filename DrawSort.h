#ifndef DRAWSORT_H
#define DRAWSORT_H
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "SortControl.h"

class DrawSort {
public:
	DrawSort();
	void drawSort(int index, std::vector<int>& array, sf::RenderWindow& window);

private:
};

#endif