#ifndef SRC_GAME_STATE_PLAYING
#define SRC_GAME_STATE_PLAYING
#include "../../Framework/pch.hpp"

#include "../Entity/world.hpp"

class PlayingState : public State
{
public:
    PlayingState(Context &context);

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    Context &m_context;
    unsigned cur_level;

    const unsigned MAX_LEVEL;
    bool is_exit, is_pause;
};
#endif /* SRC_GAME_STATE_PLAYING */
