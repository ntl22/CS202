#ifndef SRC_GAME_STATE_PAUSE
#define SRC_GAME_STATE_PAUSE
#include "../../Framework/pch.hpp"

#include "../Entity/timer.hpp"

class PauseState : public State
{
public:
    PauseState(Context &context,
               Timer &timer,
               std::function<void(std::string)>& save_f);

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    Context &m_context;
    Timer &m_timer;

    std::unique_ptr<Button> buttons[3];
    int cur;

    std::function<void(std::string)>& callback;

    sf::Text text_pause;
    sf::Font font_pause;
};
#endif /* SRC_GAME_STATE_PAUSE */
