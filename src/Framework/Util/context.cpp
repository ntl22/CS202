#include "context.hpp"

#include "identifier.hpp"

Context::Context()
{
    window = std::make_unique<sf::RenderWindow>();
    states = std::make_unique<StateStack>();
    textures = std::make_unique<TextureMap>();
    fonts = std::make_unique<FontMap>();
    sounds = std::make_unique<SoundManager>();
    musics = std::make_unique<MusicPlayer>();
}
