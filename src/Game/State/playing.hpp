#ifndef SRC_GAME_STATE_PLAYING
#define SRC_GAME_STATE_PLAYING
#include "../../Framework/pch.hpp"

#include "../Entity/world.hpp"

#include "pause.hpp"
#include "timer.hpp"

class PlayingState : public State
{
public:
    PlayingState(Context &context);

    // void handleEvent(const sf::Event &ev) override;
    // void update(sf::Time dt) override;
    // void draw() override;
    // Timer timer;

private:
    Context &m_context;
    std::vector<World> worlds;
};
#endif /* SRC_GAME_STATE_PLAYING */
