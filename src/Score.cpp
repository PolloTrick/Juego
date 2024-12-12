#include "Score.hpp"

Score::Score() {
    // Iniciamos con puntajes vacíos
}

void Score::updateScore(int player1, int player2) {
    player1ScoreShapes.clear();
    player2ScoreShapes.clear();

    for (int i = 0; i < player1; ++i) {
        sf::RectangleShape rect(sf::Vector2f(20.0f, 20.0f));
        rect.setFillColor(sf::Color::Red);
        rect.setPosition(50 + i * 25, 20);
        player1ScoreShapes.push_back(rect);
    }

    for (int i = 0; i < player2; ++i) {
        sf::RectangleShape rect(sf::Vector2f(20.0f, 20.0f));
        rect.setFillColor(sf::Color::Blue);
        rect.setPosition(700 - i * 25, 20);
        player2ScoreShapes.push_back(rect);
    }
}

void Score::draw(sf::RenderWindow& window) {
    for (const auto& rect : player1ScoreShapes) {
        window.draw(rect);
    }
    for (const auto& rect : player2ScoreShapes) {
        window.draw(rect);
    }
}
