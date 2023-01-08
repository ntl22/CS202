#include "sound.hpp"

void SoundManager::load(SOUNDBUFFERS id, const std::string &path)
{
    soundbuffers.load(id, path);
}

void SoundManager::play(SOUNDBUFFERS id)
{
    current.push_back(sf::Sound(soundbuffers.get(id)));
    current.back().play();
}

void SoundManager::removeStoppedSounds()
{
    current.remove_if([](sf::Sound &sound)
                      { return sound.getStatus() == sf::SoundSource::Stopped; });
}
