#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include "constants.hpp"
#include "star.hpp"

#include <array>

int main() {
    sf::RenderWindow window{
        sf::VideoMode(window_width, window_height),
        "Starfield",
        sf::Style::Titlebar | sf::Style::Close,
    };
    window.setVerticalSyncEnabled(true);

    std::array<star, 800> stars{};

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (clock.getElapsedTime().asMilliseconds() > 5) {
            clock.restart();
            for (auto& star : stars) {
                star.update();
            }
        }
        window.clear();
        for (const auto& star : stars) {
            star.show(&window);
        }
        window.display();
    }
}
