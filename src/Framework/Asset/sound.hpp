#ifndef SRC_FRAMEWORK_ASSET_SOUND
#define SRC_FRAMEWORK_ASSET_SOUND
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "manager.hpp"

#include <list>

enum class SOUNDBUFFERS;

class SoundManager : private sf::NonCopyable
{
public:
    void load(SOUNDBUFFERS id, const std::string &path);
    void play(SOUNDBUFFERS id);

    void removeStopSounds();

private:
    AssetMap<SOUNDBUFFERS, sf::SoundBuffer> soundbuffers;
    std::list<sf::Sound> list_sound;
};

#endif /* SRC_FRAMEWORK_ASSET_SOUND */
