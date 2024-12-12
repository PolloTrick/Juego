#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle {
private:
    sf::RectangleShape shape;
    float speed;

public:
    Paddle(float width, float height, float posX, float posY, sf::Color color);

    void move(float dx, float dy);
    sf::RectangleShape& getShape();
    float getSpeed() const;
};

#endif
