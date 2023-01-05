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
    m_context.sounds->play(SOUNDBUFFERS::light);
}

void TrafficLight::updateGreen()
{
    light_sprite.setTexture(m_context.textures->get(TEXTURES::lightGreen));
    is_red = false;
    m_context.sounds->play(SOUNDBUFFERS::light);
}

bool TrafficLight::isRed() const { return is_red; }
