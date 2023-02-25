#include <SFMLSnake.hpp>

#include <SFML/Graphics.hpp>

int main() {
    // set random seed
    srand(time(NULL));

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Snake");

    window.setFramerateLimit(10);

    // create the game instance
    SFMLSnake game;
    game.generateApple();

    // set up the score text
    sf::Font font;
    if (!font.loadFromFile("../fonts/arial.ttf")) {
        return -1;
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    // main game loop
    while (window.isOpen() && !game.gameOver()) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    game.setDirection(sf::Vector2i(-1, 0));
                }
                if (event.key.code == sf::Keyboard::Right) {
                    game.setDirection(sf::Vector2i(1, 0));
                }
                if (event.key.code == sf::Keyboard::Up) {
                    game.setDirection(sf::Vector2i(0, -1));
                }
                if (event.key.code == sf::Keyboard::Down) {
                    game.setDirection(sf::Vector2i(0, 1));
                }
            }
        }

        // update the game
        game.update();

        // update the score text
        scoreText.setString("Score: " + std::to_string(game.getScore()));

        // clear the screen
        window.clear();

        // draw the game objects
        game.draw(window);
        window.draw(scoreText);

        // display the screen
        window.display();
    }

    return 0;
}