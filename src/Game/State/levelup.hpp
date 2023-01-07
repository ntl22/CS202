#ifndef SRC_GAME_STATE_LEVELUP
#define SRC_GAME_STATE_LEVELUP
#include "../../Framework/pch.hpp"

class LevelUpState : public State
{
public:
    LevelUpState(Context &context, const int &level);

    void handleEvent(const sf::Event &ev);
    void update(sf::Time dt);
    void draw();

private:
    sf::Text next_level, press_enter;

    Context &m_context;
};

#endif /* SRC_GAME_STATE_LEVELUP */
