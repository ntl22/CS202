#include "light.hpp"

TrafficLight::TrafficLight(Context &context, sf::Time delta)
    : m_context(context),
      between(delta)
{
    updateGreen();
    is_red = false;
}

void TrafficLight::updateRed()
{
    light_sprite.setTexture(m_context.textures->get(TEXTURES::lightRed));
    is_red = true;
}

void TrafficLight::updateGreen()
{
    light_sprite.setTexture(m_context.textures->get(TEXTURES::lightGreen));
    is_red = false;
}

bool TrafficLight::isRed() const { return is_red; }
