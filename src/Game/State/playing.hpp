#ifndef SRC_GAME_STATE_PLAYING
#define SRC_GAME_STATE_PLAYING
#include "../../Framework/pch.hpp"

class PlayingState : public State
{
public:
    PlayingState(std::shared_ptr<Context> context);

    void handleEvent(const sf::Event& ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    void pause_game();

    std::shared_ptr<Context> context;

    sf::Text testing;
};

#endif /* SRC_GAME_STATE_PLAYING */
