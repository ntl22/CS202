#ifndef SRC_GAME_ENTITY_TIMER
#define SRC_GAME_ENTITY_TIMER
#include "../../Framework/pch.hpp"

class Timer
{
public:
    Timer(Context& context);

    sf::Time getTime()
    {
        return timer;
    }

    sf::Time update();
    void exitPauseState();
    void draw(sf::RenderWindow& window);

private:
    void loadGame(std::ifstream& fin);
    void saveGame(std::ofstream& fout);

    void updateString();

    sf::Text to_text;
    sf::Time timer;
    sf::Clock clock;

    friend class PlayingState;
};

#endif /* SRC_GAME_ENTITY_TIMER */
