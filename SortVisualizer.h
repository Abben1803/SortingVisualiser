#include <SFML/Graphics.hpp>
#include "SortControl.h"
#include "InsertionSort.h"
#include "DrawSort.h"
#include <vector>
#include <chrono>
#include <thread>

class SortVisualizer {
public:
    SortVisualizer(int width, int height, const std::string& title);
    SortVisualizer() = default;
    void run();

private:
    void handleEvents();
    void update();
    void draw();

    sf::RenderWindow window;
    SortControl sc;
    InsertionSort is;
    DrawSort ds;
    std::vector<int> array;
};

SortVisualizer::SortVisualizer(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title) {
    sc.populateArray(array, 1000);
}

void SortVisualizer::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}


void SortVisualizer::draw() {
    ds.drawSort(array.size(), array, window);
}

void SortVisualizer::run() {
    while (window.isOpen()) {
        handleEvents();
        if (!sc.isSorted(array)) {
            is.insertionSort(array, array.size(), [&]() {
                ds.drawSort(array.size(), array, window);
                window.display(); 
                
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                });
        }

        draw();
    }
}
