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
    std::function<void(std::string path)> saveGame_func;
    std::function<void(std::string path)> loadGame_func;

    Context &m_context;
    Timer timer;
    
    std::unique_ptr<World> world;
    unsigned cur_level;

    const unsigned MAX_LEVEL;

    const std::array<int, 5> speed;

    friend class LoadState;
    friend class SaveState;
};
#endif /* SRC_GAME_STATE_PLAYING */
