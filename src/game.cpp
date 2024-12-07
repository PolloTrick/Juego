#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main() {
    // Crear ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ping Pong - Mejora de Colisiones");
    window.setFramerateLimit(60);

    // Crear raquetas
    sf::RectangleShape paddle1(sf::Vector2f(20, 100));
    paddle1.setFillColor(sf::Color::Red);
    paddle1.setPosition(30, 250);

    sf::RectangleShape paddle2(sf::Vector2f(20, 100));
    paddle2.setFillColor(sf::Color::Blue);
    paddle2.setPosition(750, 250);

    // Crear pelota
    sf::CircleShape ball(10);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(400, 300);

    // Velocidad de raquetas y pelota
    float paddleSpeed = 5.0f;
    sf::Vector2f ballSpeed(-4.0f, -4.0f);

    while (window.isOpen()) {
        // Manejo de eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controles para mover las raquetas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paddle1.getPosition().y > 0)
            paddle1.move(0, -paddleSpeed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && paddle1.getPosition().y < 500)
            paddle1.move(0, paddleSpeed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle2.getPosition().y > 0)
            paddle2.move(0, -paddleSpeed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paddle2.getPosition().y < 500)
            paddle2.move(0, paddleSpeed);

        // Movimiento de la pelota
        ball.move(ballSpeed);

        // Rebote contra los bordes superiores e inferiores
        if (ball.getPosition().y <= 0 || ball.getPosition().y >= 590)
            ballSpeed.y = -ballSpeed.y;

        // Rebote contra las raquetas
        if (ball.getGlobalBounds().intersects(paddle1.getGlobalBounds())) {
            ballSpeed.x = std::abs(ballSpeed.x); // Asegurar dirección correcta
            ball.setPosition(paddle1.getPosition().x + paddle1.getSize().x + 1, ball.getPosition().y);
        }
        if (ball.getGlobalBounds().intersects(paddle2.getGlobalBounds())) {
            ballSpeed.x = -std::abs(ballSpeed.x); // Asegurar dirección correcta
            ball.setPosition(paddle2.getPosition().x - ball.getRadius() * 2 - 1, ball.getPosition().y);
        }

        // Verificar si la pelota cruza los bordes laterales
        if (ball.getPosition().x < 0 || ball.getPosition().x > 800) {
            ball.setPosition(400, 300); // Reiniciar la posición de la pelota
            ballSpeed = sf::Vector2f(-4.0f, -4.0f); // Reiniciar la velocidad
        }

        // Renderizado
        window.clear(sf::Color::Black);
        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(ball);
        window.display();
    }

    return 0;
}
