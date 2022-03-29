#include "star.hpp"

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"
#include "constants.hpp"
#include "cpprocessing/math/map.hpp"

#include <random>

using rangef = pcs::math::range<float>;
using pcs::math::map;

static std::random_device rd;
static std::default_random_engine eng{rd()};

constexpr float zoom_speed = static_cast<float>(window_width) * 0.01f;

star::star()
    : m_x(std::uniform_real_distribution<float>{
          -static_cast<float>(window_width),
          static_cast<float>(window_width),
      }(eng)),
      m_y(std::uniform_real_distribution<float>{
          -static_cast<float>(window_height),
          static_cast<float>(window_height),
      }(eng)),
      m_z(std::uniform_real_distribution<float>{
          0.0f,
          static_cast<float>(window_width),
      }(eng)) {}

void star::update() {
    m_z -= zoom_speed;
    if (m_z < 1.0f) {
        m_x = std::uniform_real_distribution<float>{
            -static_cast<float>(window_width),
            static_cast<float>(window_width),
        }(eng);
        m_y = std::uniform_real_distribution<float>{
            -static_cast<float>(window_height),
            static_cast<float>(window_height),
        }(eng);
        m_z = window_width;
    }
}

void star::show(sf::RenderTarget* target) const {
    float sx = map(m_x / m_z, rangef{0, 1}, rangef{0, window_width}) +
        static_cast<float>(window_width) / 2;
    float sy = map(m_y / m_z, rangef{0, 1}, rangef{0, window_height}) +
        static_cast<float>(window_height) / 2;
    float r = map(m_z, rangef{0, window_width}, rangef{8, 0});

    auto circle = sf::CircleShape{r};
    circle.setPosition(sf::Vector2f{sx, sy});
    circle.setFillColor(sf::Color::White);
    target->draw(circle);
}
