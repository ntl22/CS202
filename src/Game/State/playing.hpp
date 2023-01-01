#ifndef SRC_GAME_STATE_PLAYING
#define SRC_GAME_STATE_PLAYING
#include "../../Framework/pch.hpp"

#include "../Entity/people.hpp"
#include "../Entity/animal.hpp"
#include "../Entity/vehicle.hpp"
#include "../Entity/road.hpp"

#include "pause.hpp"

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

    bool is_exit;
};

#endif /* SRC_GAME_STATE_PLAYING */
