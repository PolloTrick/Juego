#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Score.hpp"
#include "ImageManager.hpp"
#include "SoundManager.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ping Pong");
    window.setFramerateLimit(60);

    // Inicialización de música
    sf::Music backgroundMusic;
    if (!backgroundMusic.openFromFile("assets/musica/soundtrack.mp3"))
    {
        std::cerr << "Error al cargar la música de fondo" << std::endl;
        return -1;
    }
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(5.f);
    backgroundMusic.play();

    // Inicialización de sonidos
    SoundManager soundManager;

    // Inicialización de imágenes para victoria
    sf::Texture redWinsTexture, blueWinsTexture;
    if (!redWinsTexture.loadFromFile("assets/images/redwins.png") ||
        !blueWinsTexture.loadFromFile("assets/images/bluewins.png"))
    {
        std::cerr << "Error al cargar las imágenes de victoria" << std::endl;
        return -1;
    }
    sf::Sprite redWinsSprite(redWinsTexture);
    sf::Sprite blueWinsSprite(blueWinsTexture);

    // Redimensionar las imágenes (50% del tamaño de la ventana)
    float scaleX = 0.5f; // 50% del ancho
    float scaleY = 0.5f; // 50% de la altura

    redWinsSprite.setScale(scaleX, scaleY);
    blueWinsSprite.setScale(scaleX, scaleY);

    // Ajustar posición de las imágenes para que estén centradas en la ventana
    sf::FloatRect redWinsBounds = redWinsSprite.getLocalBounds();
    redWinsSprite.setPosition((800 - redWinsBounds.width * scaleX) / 2, (600 - redWinsBounds.height * scaleY) / 2);

    sf::FloatRect blueWinsBounds = blueWinsSprite.getLocalBounds();
    blueWinsSprite.setPosition((800 - blueWinsBounds.width * scaleX) / 2, (600 - blueWinsBounds.height * scaleY) / 2);

    // Crear objetos del juego
    Ball ball(10.0f, 400.0f, 300.0f);
    Paddle paddle1(20.0f, 100.0f, 30.0f, 250.0f, sf::Color::Red);
    Paddle paddle2(20.0f, 100.0f, 750.0f, 250.0f, sf::Color::Blue);
    Score score;

    int score1 = 0, score2 = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controles de las raquetas
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

        if (ball.getShape().getGlobalBounds().intersects(paddle1.getShape().getGlobalBounds()))
        {
            ball.reboundHorizontal();
            soundManager.playSound("assets/sounds/raqueta.mp3");
            ball.getShape().move(5, 0);
        }

        if (ball.getShape().getGlobalBounds().intersects(paddle2.getShape().getGlobalBounds()))
        {
            ball.reboundHorizontal();
            soundManager.playSound("assets/sounds/raqueta.mp3");
            ball.getShape().move(-5, 0);
        }

        // Verificar goles
        if (ball.getShape().getPosition().x < 0)
        {
            score2++;
            ball.resetPosition(400, 300);
            soundManager.playSound("assets/sounds/gol.mp3");
        }

        if (ball.getShape().getPosition().x > 800)
        {
            score1++;
            ball.resetPosition(400, 300);
            soundManager.playSound("assets/sounds/gol.mp3");
        }

        score.updateScore(score1, score2);

        // Verificar si alguien gana
        if (score1 >= 5 || score2 >= 5)
        {
            window.clear();

            if (score1 >= 5)
            {
                window.draw(redWinsSprite); // Mostrar imagen de victoria del jugador 1
            }
            else
            {
                window.draw(blueWinsSprite); // Mostrar imagen de victoria del jugador 2
            }

            window.display();
            sf::sleep(sf::seconds(5));
            break;
        }

        // Dibujar en la ventana
        window.clear();
        window.draw(paddle1.getShape());
        window.draw(paddle2.getShape());
        window.draw(ball.getShape());
        score.draw(window);
        window.display();
    }

    return 0;
}