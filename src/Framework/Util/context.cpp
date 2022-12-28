#include "context.hpp"

#include "identifier.hpp"

Context::Context()
{
    states = std::make_unique<StateStack>();
    window = std::make_unique<sf::RenderWindow>();
    fonts = std::make_unique<MediaMachine<FONTS, sf::Font>>();
    textures = std::make_unique<MediaMachine<TEXTURES, sf::Texture>>();
}
