#include "DrawSort.h"


DrawSort::DrawSort(){ }

void DrawSort::drawSort(int index, std::vector<int>& array, sf::RenderWindow& window) {
    SortControl srtc;
    window.clear(sf::Color::Black); // Clear the window with a black background
    for (int i = 0; i < index; i++) {
        sf::RectangleShape block(sf::Vector2f(10, array[i]));
        block.setPosition(i * 12, 600 - array[i]);
        // if sorted the block is green otherwise its white.
        block.setFillColor(srtc.isSorted(array) || i == index ? sf::Color::Green : sf::Color::White);
        window.draw(block);
    }
}
