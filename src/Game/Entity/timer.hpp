#ifndef SRC_GAME_STATE_TIMER
#define SRC_GAME_STATE_TIMER
#include "../../Framework/pch.hpp"

class Timer {
public:
    Timer(Context& context);

    void pushPauseState();
    void update();

    void draw(sf::RenderWindow& window);
private:
    std::string formatTime();

    sf::Text text_timer;
    sf::Font font_timer;

    sf::Clock clock;
    sf::Time tmp_time;
    unsigned sec, min, hour;
    bool from_pause_state;
};


#endif /* SRC_GAME_STATE_PLAYING */