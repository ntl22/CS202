#ifndef SRC_GAME_STATE_TIMER
#define SRC_GAME_STATE_TIMER
#include "../../Framework/pch.hpp"
#include "../Entity/people.hpp"

#include "pause.hpp"
#include <sstream>
#include <sstream>

class Timer {
public:
    Timer(Context& context);

    sf::Time getPlayingTime();
    std::string formatTime(const sf::Time&);

    /*void pause();
    void resume();*/
    //void handleEvent(/*const sf::Event& ev*/bool isPause) ;
    //void update(bool isPause);
    void draw(sf::RenderWindow& window);
private:
    //bool is_pause;

    sf::Text text_timer;
    sf::Font font_timer;

    sf::Clock clock;
    int sec;
};


#endif /* SRC_GAME_STATE_PLAYING */