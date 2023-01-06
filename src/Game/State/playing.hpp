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
    void saveGame(std::string path);
    void loadGame(std::string path);

    Context &m_context;
    Timer timer;
    
    std::unique_ptr<World> world;
    unsigned cur_level;

    const unsigned MAX_LEVEL;
    bool is_exit;

    const std::array<int, 5> speed;

    friend class LoadState;
    friend class SaveState;
};
#endif /* SRC_GAME_STATE_PLAYING */
