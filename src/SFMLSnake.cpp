#include <SFMLSnake.hpp>

#include <iostream>

SFMLSnake::SFMLSnake() {
    // initialize the snake with a starting position and size
    body.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
    body[0].setPosition(200, 200);
    direction = sf::Vector2i(1, 0);
}

void SFMLSnake::update() {
    // move the snake in the current direction
    sf::Vector2f newPos = body[0].getPosition() + sf::Vector2f(direction.x * 10, direction.y * 10);
    // check for collision with the walls
    if (newPos.x < 0 || newPos.x >= 800 || newPos.y < 0 || newPos.y >= 600) {
        std::cout << "Game Over!" << std::endl;
        isGameOver = true;
        return;
    }
    // check for collision with the body
    for (size_t i = 1; i < body.size(); i++) {
        if (body[i].getPosition() == newPos) {
            std::cout << "Game Over!" << std::endl;
            isGameOver = true;
            return;
        }
    }

    // move the head
    body[0].setPosition(newPos);

    // check for collision with the apple
    if (body[0].getGlobalBounds().intersects(apple.getGlobalBounds())) {
        body.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
        body[body.size() - 1].setPosition(body[body.size() - 2].getPosition());
        apple.setPosition(rand() % 800, rand() % 600);
        score++;
        std::cout << "Score: " << score << std::endl;
    }
    // move the body segments
    for (int i = body.size() - 1; i > 0; i--) {
        body[i].setPosition(body[i - 1].getPosition());
    }
}

void SFMLSnake::draw(sf::RenderWindow& window) {
    // draw the snake and apple to the screen
    window.draw(apple);
    for (auto& segment : body) {
        window.draw(segment);
    }
}

void SFMLSnake::generateApple() {
    apple.setFillColor(sf::Color::Red);
    apple.setSize(sf::Vector2f(10, 10));
    apple.setPosition(rand() % 800, rand() % 600);
}

bool SFMLSnake::gameOver() {
    return isGameOver;
}

int SFMLSnake::getScore() {
    return score;
}

void SFMLSnake::setDirection(sf::Vector2i newDirection) {
    // prevent the snake from turning back on itself
    if (newDirection.x == -direction.x || newDirection.y == -direction.y) {
        return;
    }
    direction = newDirection;
}
