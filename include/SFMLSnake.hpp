#ifndef SFML_SNAKE_HPP
#define SFML_SNAKE_HPP

#include <SFML/Graphics.hpp>

class SFMLSnake {
public:
    SFMLSnake();

    void update();
    void draw(sf::RenderWindow& window);
    void generateApple();
    bool gameOver();
    int getScore();
    void setDirection(sf::Vector2i newDirection);

private:
    std::vector<sf::RectangleShape> body;
    sf::RectangleShape apple;
    sf::Vector2i direction;
    bool isGameOver = false;
    int score = 0;
};

#endif /* SFML_SNAKE_HPP */