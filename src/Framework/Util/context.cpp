#include "context.hpp"

#include "identifier.hpp"

Context::Context()
{
    window = std::make_unique<sf::RenderWindow>();
    states = std::make_unique<StateStack>();
    textures = std::make_unique<AssetMap<TEXTURES, sf::Texture>>();
    fonts = std::make_unique<AssetMap<FONTS, sf::Font>>();
    sounds = std::make_unique<AssetMap<SOUNDBUFFERS, sf::SoundBuffer>>();
    musics = std::make_unique<MusicPlayer>();
}
