#ifndef SRC_GAME_STATE_PLAYING
#define SRC_GAME_STATE_PLAYING
#include "../../Framework/pch.hpp"

#include "../Entity/world.hpp"

class PlayingState : public State
{
public:
    PlayingState(Context &context);

    ~PlayingState();

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

    std::function<void(std::string)> saveGame;
    std::function<void(std::string)> loadGame;

private:
    Context &m_context;
    unsigned cur_level;

    std::unique_ptr<World> world;

    std::vector<unsigned> speed;

    const unsigned MAX_LEVEL;
};

#endif /* SRC_GAME_STATE_PLAYING */
