#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "constants.hpp"
#include "snake.hpp"

int main() {
    sf::RenderWindow window{
        sf::VideoMode(window_width, window_height),
        "Snake",
        sf::Style::Titlebar | sf::Style::Close,
    };
    window.setVerticalSyncEnabled(true);

    snake s;

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    s.dir(0, -1);
                } else if (event.key.code == sf::Keyboard::Down) {
                    s.dir(0, 1);
                } else if (event.key.code == sf::Keyboard::Left) {
                    s.dir(-1, 0);
                } else if (event.key.code == sf::Keyboard::Right) {
                    s.dir(1, 0);
                }
            }
        }
        if (clock.getElapsedTime().asMilliseconds() > 100) {
            clock.restart();
            s.update();
        }
        window.clear(sf::Color{51, 51, 51});
        s.show(&window);
        window.display();
    }
}
