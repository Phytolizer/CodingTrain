#pragma once

#include "SFML/Graphics/RenderTarget.hpp"

class star {
    float m_x;
    float m_y;
    float m_z;

  public:
    star();
    void update();
    void show(sf::RenderTarget* target) const;
};
