#ifndef SRC_GAME_STATE_PAUSE
#define SRC_GAME_STATE_PAUSE
#include "../../Framework/pch.hpp"

class PauseState : public State
{
public:
    PauseState(Context &context,
               bool &exit_ref, bool &pause_ref);

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    bool &is_exit, &is_pause;

    Context &m_context;

    sf::Text text_pause;
    sf::Font font_pause;
};
#endif /* SRC_GAME_STATE_PAUSE */
