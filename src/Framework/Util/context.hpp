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

typedef AssetMap<TEXTURES, sf::Texture> TextureMap;
typedef AssetMap<FONTS, sf::Font> FontMap;
typedef AssetMap<SOUNDBUFFERS, sf::SoundBuffer> SoundMap;

struct Context
{
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<StateStack> states;
    std::unique_ptr<TextureMap> textures;
    std::unique_ptr<FontMap> fonts;
    std::unique_ptr<SoundMap> sounds;
    std::unique_ptr<MusicPlayer> musics;

    Context();

    ~Context() = default;
};

#endif /* SRC_FRAMEWORK_UTIL_CONTEXT */
