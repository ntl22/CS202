#include "music.hpp"

MusicPlayer::MusicPlayer()
    : volume(100.f), loop(false) {}

void MusicPlayer::load(MUSICS id, const std::string &path) { map[id] = path; }

void MusicPlayer::setVolume(float volume) { this->volume = volume; }

void MusicPlayer::setLoop(bool loop) { this->loop = loop; }
float MusicPlayer::getVolume() const { return volume; }
void MusicPlayer::play(MUSICS id)
{
    auto find = map.find(id);

    if (find == map.end())
        throw std::runtime_error("MusicPlayer::play(): id invalid");

    if (!current.openFromFile(find->second))
        throw std::runtime_error("MusicPlayer::play(): path " + find->second + " invalid");

    current.setVolume(volume);
    current.setLoop(loop);
    current.play();
}

void MusicPlayer::stop()
{
    if (current.getStatus() == sf::Music::Playing)
        current.stop();
}

void MusicPlayer::pause(bool pause)
{
    pause ? current.pause() : current.play();
}
