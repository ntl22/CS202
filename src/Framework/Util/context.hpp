#ifndef SRC_FRAMEWORK_UTIL_CONTEXT
#define SRC_FRAMEWORK_UTIL_CONTEXT
#include "../Asset/manager.hpp"
#include "../State/manager.hpp"
#include "./Asset/music.hpp"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

#include <memory>

enum class FONTS;
enum class TEXTURES;
enum class SOUNDBUFFERS;

class StateStack;

struct Context
{
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<StateStack> states;
    std::unique_ptr<AssetMap<TEXTURES, sf::Texture>> textures;
    std::unique_ptr<AssetMap<FONTS, sf::Font>> fonts;
    std::unique_ptr<AssetMap<SOUNDBUFFERS, sf::SoundBuffer>> sounds;
    std::unique_ptr<MusicPlayer> musics;

    Context();

    ~Context() = default;
};

#endif /* SRC_FRAMEWORK_UTIL_CONTEXT */
