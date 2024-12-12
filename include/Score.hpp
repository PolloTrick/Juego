#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Score {
private:
    std::vector<sf::RectangleShape> player1ScoreShapes;
    std::vector<sf::RectangleShape> player2ScoreShapes;

public:
    Score();

    void updateScore(int player1, int player2);
    void draw(sf::RenderWindow& window);
};

#endif
