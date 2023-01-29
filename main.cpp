#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
using namespace sf;
using namespace std;
class Ball {
    private:
        CircleShape shape;
        Vector2f velocity;

    public:
        Ball(float r = 10.f, float x = 400.f, float y = 300.f) {
            shape.setRadius(r);
            shape.setPosition(x, y);
        };
        void setVelocity(float x, float y) {
            velocity.x = x;
            velocity.y = y;
        };
        void setPosition(float x, float y) {
            shape.setPosition(x, y);
        }
        Vector2f getPosition() {return shape.getPosition();}
        Vector2f getVelocity() {return velocity;}
        float getRadius() {return shape.getRadius();}
        void update() {
            shape.move(velocity);
        };
        void draw(RenderTarget& target) {
            target.draw(shape);
        };
        bool checkCollisionWithBlock() {
            
        }
};
class Block {
    private:
        RectangleShape shape;
        bool destroyed = false;
    
    public:
        Block(float x = 50.f, float y = 10.f) {
            Vector2f size(x, y);
            shape.setSize(size);
        }
        RectangleShape getShape() {return shape;}
        void setPosition(float x = 50.f, float y = 400.f) {
            shape.setPosition(x, y);
        }
        void destroy() {destroyed = true;}
        bool isDestroyed() {return destroyed;}
        void draw(RenderTarget& target) {
            if (!destroyed) target.draw(shape);
        }
};
void handleCollision(Ball& ball, RenderWindow& window) {
    Vector2f position = ball.getPosition();
    Vector2f velocity = ball.getVelocity();
    float radius = ball.getRadius()*2;
    if (position.x - radius <= 0) velocity.x = abs(velocity.x);
    else if (position.x + radius >= window.getSize().x) velocity.x = -abs(velocity.x);
    if (position.y - radius <= 0) velocity.y = abs(velocity.y);
    else if (position.y + radius >= window.getSize().y) velocity.y = -abs(velocity.y);
    ball.setVelocity(velocity.x, velocity.y);
};

int main() {
    RenderWindow window(VideoMode(800, 600), "Breakout");
    window.setFramerateLimit(60);
    // initianlize ball class
    Ball ball;
    ball.setVelocity(10.f, 10.f);
    ball.setPosition(780,580);
    Block block;
    block.setPosition();
    // looping in window
    while (window.isOpen()) {
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
            }
            //clear window
            window.clear();
            // main program
            handleCollision(ball, window);
            ball.update();
            ball.draw(window);
            block.draw(window);
            // logic
            // render drawing to window
            window.display();
        }
    }
}