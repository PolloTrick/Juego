#include "Paddle.hpp"

Paddle::Paddle(float width, float height, float posX, float posY, sf::Color color) 
    : shape(sf::Vector2f(width, height)), speed(5.0f) {
    shape.setPosition(posX, posY);
    shape.setFillColor(color);
}

void Paddle::move(float dx, float dy) {
    shape.move(dx, dy);
}

sf::RectangleShape& Paddle::getShape() {
    return shape;
}

float Paddle::getSpeed() const {
    return speed;
}
