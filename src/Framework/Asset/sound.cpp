#include "sound.hpp"

void SoundManager::load(SOUNDBUFFERS id, const std::string &path)
{
    soundbuffers.load(id, path);
}

void SoundManager::play(SOUNDBUFFERS id)
{
    current.setBuffer(soundbuffers.get(id));
    current.play();
}
