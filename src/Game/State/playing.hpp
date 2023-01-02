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
<<<<<<< HEAD
    People people;
    Road a;
    Timer timer;

    World world;

    bool is_exit;
=======
    std::vector<World> worlds;
>>>>>>> f45b399e51cfdf55223d2e6425ca267f3570304b
};
#endif /* SRC_GAME_STATE_PLAYING */
