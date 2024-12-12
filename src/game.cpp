#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Score.hpp"

int main() {
    // Velocidad inicial de la pelota
    sf::Vector2f ballSpeed(300.f, 300.f);

    int frameCount = 0;                // Contador de frames
    const int frameInterval = 120;     // Aumenta la velocidad cada 120 frames
    float speedIncreaseFactor = 1.10f; // Incremento del 10% por intervalo

    sf::RenderWindow window(sf::VideoMode(800, 600), "Ping Pong");
    window.setFramerateLimit(60);

    Ball ball(10.0f, 400.0f, 300.0f);
    Paddle paddle1(20.0f, 100.0f, 30.0f, 250.0f, sf::Color::Red);
    Paddle paddle2(20.0f, 100.0f, 750.0f, 250.0f, sf::Color::Blue);
    Score score;

    int score1 = 0, score2 = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controles de raquetas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paddle1.getShape().getPosition().y > 0)
            paddle1.move(0, -paddle1.getSpeed());
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && paddle1.getShape().getPosition().y < 500)
            paddle1.move(0, paddle1.getSpeed());

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle2.getShape().getPosition().y > 0)
            paddle2.move(0, -paddle2.getSpeed());
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paddle2.getShape().getPosition().y < 500)
            paddle2.move(0, paddle2.getSpeed());

        // Movimiento de la pelota
        ball.move();

        // Rebote de la pelota
        if (ball.getShape().getPosition().y <= 0 || ball.getShape().getPosition().y >= 590)
            ball.reboundVertical();

        // Ajuste en el rebote para evitar el "pegado" de la pelota en la raqueta
        if (ball.getShape().getGlobalBounds().intersects(paddle1.getShape().getGlobalBounds())) {
            ball.reboundHorizontal();
            // Desplazar la pelota ligeramente para evitar que quede pegada
            ball.getShape().move(5, 0);
        }

        if (ball.getShape().getGlobalBounds().intersects(paddle2.getShape().getGlobalBounds())) {
            ball.reboundHorizontal();
            // Desplazar la pelota ligeramente para evitar que quede pegada
            ball.getShape().move(-5, 0);
        }

        // Verificar goles
        if (ball.getShape().getPosition().x < 0) {
            score2++;
            ball.resetPosition(400, 300);
        }

        if (ball.getShape().getPosition().x > 800) {
            score1++;
            ball.resetPosition(400, 300);
        }

        score.updateScore(score1, score2);

        // Verificar si alguno de los jugadores ha alcanzado 5 puntos
        if (score1 >= 5 || score2 >= 5) {
            window.clear();
            sf::RectangleShape background(sf::Vector2f(800, 600));

            // Asignar el color de fondo según el jugador que gane
            if (score1 >= 5) {
                background.setFillColor(sf::Color::Red);  // Fondo rojo si gana el jugador 1
            } else {
                background.setFillColor(sf::Color::Blue); // Fondo azul si gana el jugador 2
            }

            window.draw(background); // Dibuja el fondo
            sf::Font font;
            if (font.loadFromFile("arial.ttf")) {
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(50);
                text.setFillColor(sf::Color::White);
                if (score1 >= 5) {
                    text.setString("Jugador 1 Gana!");
                } else {
                    text.setString("Jugador 2 Gana!");
                }
                text.setPosition(200, 250); // Posiciona el texto en el centro
                window.draw(text);
            }
            window.display();
            sf::sleep(sf::seconds(2));  // Mostrar mensaje por 2 segundos
            break;  // Detener el juego
        }

        // Dibujar
        window.clear();
        window.draw(paddle1.getShape());
        window.draw(paddle2.getShape());
        window.draw(ball.getShape());
        score.draw(window);
        window.display();

        // Dentro del bucle principal
        frameCount++;

        // Incrementar velocidad cada frameInterval frames
        if (frameCount >= frameInterval) {
            frameCount = 0; // Reinicia el contador
            ballSpeed.x *= speedIncreaseFactor;
            ballSpeed.y *= speedIncreaseFactor;

            // Limitar la velocidad para evitar que sea incontrolable
            if (std::abs(ballSpeed.x) > 500.0f) ballSpeed.x = (ballSpeed.x > 0 ? 500.0f : -500.0f);
            if (std::abs(ballSpeed.y) > 500.0f) ballSpeed.y = (ballSpeed.y > 0 ? 500.0f : -500.0f);
        }
    }

    return 0;
}
