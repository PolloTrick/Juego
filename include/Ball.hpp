#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float radius, float startX, float startY);
    
    void move();
    void reboundVertical();
    void reboundHorizontal();
    void resetPosition(float x, float y);
    void setPosition(float x, float y);

    sf::CircleShape& getShape();
    
    // Variables de velocidad
    sf::Vector2f speed;

private:
    sf::CircleShape ballShape;
};

#endif
