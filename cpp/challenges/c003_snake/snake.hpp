#pragma once

#include "SFML/Graphics/RenderTarget.hpp"

struct snake {
    static constexpr float scale = 30.0f;

    float x = 0.0f;
    float y = 0.0f;
    float xspeed = 1.0f;
    float yspeed = 0.0f;

    void update();
    void dir(float dx, float dy);
    void show(sf::RenderTarget* target) const;
};
