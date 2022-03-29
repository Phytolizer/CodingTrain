#include "snake.hpp"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "constants.hpp"

#include <algorithm>

void snake::update() {
    x += xspeed * scale;
    y += yspeed * scale;

    x = std::clamp(x, 0.0f, static_cast<float>(window_width) - scale);
    y = std::clamp(y, 0.0f, static_cast<float>(window_height) - scale);
}

void snake::dir(float dx, float dy) {
    xspeed = dx;
    yspeed = dy;
}

void snake::show(sf::RenderTarget* target) const {
    auto rect = sf::RectangleShape(sf::Vector2f{scale, scale});
    rect.setPosition(sf::Vector2f{x, y});
    rect.setFillColor(sf::Color::White);

    target->draw(rect);
}
