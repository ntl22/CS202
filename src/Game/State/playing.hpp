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
    std::function<void(std::string)> saveGame;
    std::function<void(std::string)> loadGame;

    Context &m_context;
    unsigned cur_level;

    std::array<unsigned, 5> speed;

    const unsigned MAX_LEVEL;
};

#endif /* SRC_GAME_STATE_PLAYING */
