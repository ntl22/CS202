#include "light.hpp"

TrafficLight::TrafficLight(Context &context, sf::Time delta)
    : m_context(context),
      between(delta)
{
    light_sprite.setTexture(m_context.textures->get(TEXTURES::lightGreen));
    is_red = false;
}

void TrafficLight::updateRed()
{
    light_sprite.setTexture(m_context.textures->get(TEXTURES::lightRed));
    is_red = true;
    m_context.sounds->play(SOUNDBUFFERS::light);
    between = sf::seconds(rand() % 3 + 3.f);
}

void TrafficLight::updateGreen()
{
    light_sprite.setTexture(m_context.textures->get(TEXTURES::lightGreen));
    is_red = false;
    m_context.sounds->play(SOUNDBUFFERS::light);
    between = sf::seconds(rand() % 3 + 3.f);
}

bool TrafficLight::isRed() const { return is_red; }

void TrafficLight::saveGame(std::ofstream& fout) {
    fout << between.asMilliseconds() << '\n' << last_update.asMilliseconds() << '\n' << is_red << '\n';
}

void TrafficLight::loadGame(std::ifstream& fin) {
    int bet, last;
    fin >> bet >> last >> is_red;
    between = sf::milliseconds(bet);
    last_update = sf::microseconds(last);
    if (is_red == true)
        light_sprite.setTexture(m_context.textures->get(TEXTURES::lightRed));
    else
        light_sprite.setTexture(m_context.textures->get(TEXTURES::lightGreen));
}