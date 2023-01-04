#ifndef SRC_GAME_STATE_PAUSE
#define SRC_GAME_STATE_PAUSE
#include "../../Framework/pch.hpp"

#include "../Entity/timer.hpp"

class PauseState : public State
{
public:
    PauseState(Context &context, Timer &timer, bool &exit_ref);

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    bool &is_exit;

    Context &m_context;
    Timer &m_timer;

    std::unique_ptr<Button> buttons[3];
    int cur;

    sf::Text text_pause;
    sf::Font font_pause;
};
#endif /* SRC_GAME_STATE_PAUSE */
