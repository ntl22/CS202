#ifndef SRC_GAME_STATE_LEVELUP
#define SRC_GAME_STATE_LEVELUP
#include "../../Framework/pch.hpp"

#include "../Entity/timer.hpp"

class LevelUpState : public State
{
public:
    LevelUpState(Context &context, Timer &timer, const int &level);
    void handleEvent(const sf::Event &ev);
    void update(sf::Time dt);
    void draw();

private:
    sf::Text next_level;

    Context &m_context;
    Timer &m_timer;
};

#endif /* SRC_GAME_STATE_LEVELUP */
