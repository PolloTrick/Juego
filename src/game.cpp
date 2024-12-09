#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

int main() {
    // Crear ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ping Pong - Velocidad Progresiva");
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

    // Marcador
    int score1 = 0;
    int score2 = 0;

    // Círculos para representar el marcador
    std::vector<sf::CircleShape> scoreCircles1; // Jugador 1
    std::vector<sf::CircleShape> scoreCircles2; // Jugador 2

    bool gameOver = false;

    while (window.isOpen()) {
        // Manejo de eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Lógica del juego
        if (!gameOver) {
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
                ballSpeed.x = std::abs(ballSpeed.x);
                ball.setPosition(paddle1.getPosition().x + paddle1.getSize().x + 1, ball.getPosition().y);
                ballSpeed *= 1.05f; // Aumentar la velocidad después de cada rebote
            }
            if (ball.getGlobalBounds().intersects(paddle2.getGlobalBounds())) {
                ballSpeed.x = -std::abs(ballSpeed.x);
                ball.setPosition(paddle2.getPosition().x - ball.getRadius() * 2 - 1, ball.getPosition().y);
                ballSpeed *= 1.05f; // Aumentar la velocidad después de cada rebote
            }

            // Verificar si la pelota cruza los bordes laterales
            if (ball.getPosition().x < 0) {
                score2++;
                ball.setPosition(400, 300);
                ballSpeed = sf::Vector2f(-4.0f, -4.0f); // Restablecer la velocidad
            }
            if (ball.getPosition().x > 800) {
                score1++;
                ball.setPosition(400, 300);
                ballSpeed = sf::Vector2f(4.0f, 4.0f); // Restablecer la velocidad
            }

            // Verificar si alguien gana
            if (score1 == 5 || score2 == 5) {
                gameOver = true;
            }

            // Actualizar los círculos del marcador
            scoreCircles1.clear();
            scoreCircles2.clear();

            for (int i = 0; i < score1; ++i) {
                sf::CircleShape circle(10); // Círculo de 10 píxeles de radio
                circle.setFillColor(sf::Color::Red);
                circle.setPosition(200 + i * 30, 20); // Espaciado horizontal entre círculos
                scoreCircles1.push_back(circle);
            }

            for (int i = 0; i < score2; ++i) {
                sf::CircleShape circle(10); // Círculo de 10 píxeles de radio
                circle.setFillColor(sf::Color::Blue);
                circle.setPosition(400 + i * 30, 20); // Espaciado horizontal entre círculos
                scoreCircles2.push_back(circle);
            }

        } else {
            // Menú de reinicio
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                // Reiniciar juego
                score1 = 0;
                score2 = 0;
                ball.setPosition(400, 300);
                ballSpeed = sf::Vector2f(-4.0f, -4.0f);
                gameOver = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        // Renderizado
        window.clear(sf::Color::Black);

        if (!gameOver) {
            window.draw(paddle1);
            window.draw(paddle2);
            window.draw(ball);
        }

        // Dibujar los círculos del marcador
        for (auto& circle : scoreCircles1) {
            window.draw(circle);
        }
        for (auto& circle : scoreCircles2) {
            window.draw(circle);
        }

        if (gameOver) {
            sf::RectangleShape gameOverBox(sf::Vector2f(400, 200));
            gameOverBox.setFillColor(sf::Color::Black);
            gameOverBox.setOutlineColor(sf::Color::White);
            gameOverBox.setOutlineThickness(5);
            gameOverBox.setPosition(200, 200);
            window.draw(gameOverBox);
        }

        window.display();
    }

    return 0;
}

