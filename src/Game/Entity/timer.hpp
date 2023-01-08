#ifndef SRC_GAME_ENTITY_TIMER
#define SRC_GAME_ENTITY_TIMER
#include "../../Framework/pch.hpp"

class Timer
{
public:
    Timer(Context& context);

    sf::Time getTime();

    sf::Time update();
    void exitPauseState();
    void draw(sf::RenderWindow& window);

    void loadGame(std::ifstream& fin);
    void saveGame(std::ofstream& fout);

private:
    void updateString();

    sf::Text to_text;
    sf::Time timer;
    sf::Clock clock;
};

#endif /* SRC_GAME_ENTITY_TIMER */
