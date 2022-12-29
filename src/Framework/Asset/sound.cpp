#include "sound.hpp"

void SoundManager::load(SOUNDBUFFERS id, const std::string &path)
{
    soundbuffers.load(id, path);
}

void SoundManager::play(SOUNDBUFFERS id)
{
    list_sound.push_back(sf::Sound(soundbuffers.get(id)));
    list_sound.back().play();
}

void SoundManager::removeStopSounds()
{
    list_sound.remove_if([](const sf::Sound &sound)
                         { return sound.getStatus() == sf::Sound::Stopped; });
}
