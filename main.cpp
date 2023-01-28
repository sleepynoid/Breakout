#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
using namespace sf;
using namespace std;

RectangleShape paddle;
RectangleShape brick;
CircleShape ball;

int main() {
    // Create the game window
    RenderWindow window(VideoMode(800, 600), "Breakout");
    window.setFramerateLimit(60);

    // Load the game's assets (e.g. sprites, fonts, etc.)
    // initialize the game objects and variables
    Vector2u windowSize = window.getSize();
    Vector2f ballPosition;
    // paddle
    int SPEED = 10, PADDLE_SPEED = SPEED, BALL_SPEED = SPEED;
    paddle.setSize({100,10});
    paddle.setPosition(400,500);
    // ball
    ball.setRadius(5);
    ball.setPosition(200,200);
    // brick
    brick.setSize({80,20});
    brick.setPosition(80,100);
    cout << ball.getRadius();
    // Main game loop
    while (window.isOpen()) {
        // Handle events
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Right) {
                    paddle.move(PADDLE_SPEED,0);
                }
                else if (event.key.code == Keyboard::Left) {
                    paddle.move(-PADDLE_SPEED,0);
                }
                else if (event.key.code == Keyboard::Up) {
                    paddle.move(0, -PADDLE_SPEED);
                }
                else if (event.key.code == Keyboard::Down) {
                    paddle.move(0,PADDLE_SPEED);
                }
            }
        }
        // Update the game logic
        ball.move(0, BALL_SPEED);
        ballPosition = ball.getPosition();
        if (ballPosition.y > 0 && ballPosition.y + ball.getRadius() > windowSize.y) BALL_SPEED = -BALL_SPEED;
        else if(ballPosition.y < 0 && ballPosition.y + ball.getRadius() < windowSize.y) BALL_SPEED = -BALL_SPEED;
        if (ballPosition.x > 0 && ballPosition.x + ball.getRadius() > windowSize.x) BALL_SPEED = -BALL_SPEED;
        else if(ballPosition.x < 0 && ballPosition.x + ball.getRadius() < windowSize.x) BALL_SPEED = -BALL_SPEED;
        // Clear the window
        window.clear();

        // Draw the game graphics
        window.draw(paddle);
        window.draw(ball);
        window.draw(brick);

        // Display the window
        window.display();
    }

    return 0;
}