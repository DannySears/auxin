#include "Visualizer.h"

Visualizer::Visualizer(int width, int height)
    : window(sf::VideoMode(width, height), "Music Visualizer") {}

void Visualizer::render(const std::vector<double>& magnitudes) {
    sf::Event event;
    while (window.pollEvent(event))
        if (event.type == sf::Event::Closed)
            window.close();

    window.clear();

    float barWidth = static_cast<float>(window.getSize().x) / magnitudes.size();
    for (size_t i = 0; i < magnitudes.size(); i++) {
        float height = static_cast<float>(magnitudes[i] * 0.01);
        sf::RectangleShape bar(sf::Vector2f(barWidth - 1, height));
        bar.setPosition(i * barWidth, window.getSize().y - height);
        bar.setFillColor(sf::Color(100, 200, 255));
        window.draw(bar);
    }

    window.display();
}
