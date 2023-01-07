#ifndef SRC_GAME_STATE_PAUSE
#define SRC_GAME_STATE_PAUSE
#include "../../Framework/pch.hpp"

class PauseState : public State
{
public:
    PauseState(Context &context, std::function<void(std::string)>& f_ref);

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    Context &m_context;

    std::array<std::unique_ptr<Button>, 3> buttons;
    int cur;

    sf::Text text_pause;
    sf::Font font_pause;
};
#endif /* SRC_GAME_STATE_PAUSE */
