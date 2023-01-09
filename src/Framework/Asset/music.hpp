#ifndef SRC_FRAMEWORK_ASSET_MUSIC
#define SRC_FRAMEWORK_ASSET_MUSIC
#include <SFML/Audio.hpp>

#include <map>
#include <string>

enum class MUSICS;

class MusicPlayer
{
public:
    MusicPlayer();

    ~MusicPlayer() = default;

    void load(MUSICS id, const std::string &path);

    void setVolume(float volume);
    void setLoop(bool loop);
    float getVolume() const;
    void play(MUSICS id);
    void stop();
    void pause(bool pause);

private:
    std::map<MUSICS, std::string> map;
    sf::Music current;
    float volume;
    bool loop;
};

#endif /* SRC_FRAMEWORK_ASSET_MUSIC */
