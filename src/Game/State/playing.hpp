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

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    Context &m_context;
    People people;
    Road a;
    Timer timer;

    World world;

    bool is_exit;
};

#endif /* SRC_GAME_STATE_PLAYING */
