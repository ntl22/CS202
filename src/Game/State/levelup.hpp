#ifndef SRC_GAME_STATE_LEVELUP
#define SRC_GAME_STATE_LEVELUP
#include "../../Framework/pch.hpp"

class Timer;

class LevelUpState : public State
{
public:
    LevelUpState(Context &context,
                 Timer &timer,
                 const int &level);
    ~LevelUpState();

    void handleEvent(const sf::Event &ev);
    void update(sf::Time dt);
    void draw();

private:
    sf::Text next_level, press_enter;

    Timer &clock;

    Context &m_context;
};

#endif /* SRC_GAME_STATE_LEVELUP */
