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

private:
    std::function<void(std::string path)> saveGame;
    std::function<void(std::string path)> loadGame;

    Context &m_context;
    unsigned cur_level;
    Timer timer;

    std::unique_ptr<World> world;

    std::vector<unsigned> speed;

    const unsigned MAX_LEVEL;

    friend class LoadState;
    friend class SaveState;
};

#endif /* SRC_GAME_STATE_PLAYING */
