#ifndef SRC_FRAMEWORK_ASSET_SOUND
#define SRC_FRAMEWORK_ASSET_SOUND
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "manager.hpp"

enum class SOUNDBUFFERS;

class SoundManager
{
public:
    void load(SOUNDBUFFERS id, const std::string &path);
    void play(SOUNDBUFFERS id);

private:
    AssetMap<SOUNDBUFFERS, sf::SoundBuffer> soundbuffers;
    sf::Sound current;
};

#endif /* SRC_FRAMEWORK_ASSET_SOUND */
