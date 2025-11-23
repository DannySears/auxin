#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Visualizer {
public:
    Visualizer(int width = 800, int height = 600);
    void render(const std::vector<double>& magnitudes);

private:
    sf::RenderWindow window;
};
