#include "Ball.hpp"

Ball::Ball(float radius, float startX, float startY) {
    ballShape.setRadius(radius);
    ballShape.setFillColor(sf::Color::White);
    ballShape.setPosition(startX, startY);
    speed = sf::Vector2f(4.f, 4.f);  // Velocidad inicial más baja
}

void Ball::move() {
    ballShape.move(speed);
}

void Ball::reboundVertical() {
    speed.y = -speed.y; // Invertir la dirección vertical
}

void Ball::reboundHorizontal() {
    speed.x = -speed.x; // Invertir la dirección horizontal
}

void Ball::resetPosition(float x, float y) {
    ballShape.setPosition(x, y);
}

sf::CircleShape& Ball::getShape() {
    return ballShape;
}

void Ball::setPosition(float x, float y) {
    ballShape.setPosition(x, y);
}
