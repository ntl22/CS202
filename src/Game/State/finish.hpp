#ifndef SRC_GAME_STATE_FINISH
#define SRC_GAME_STATE_FINISH
#include "../../Framework/pch.hpp"

#include "../Entity/timer.hpp"

class FinishState : public State
{
public:
    FinishState(Context &context,
                Timer timer,
                bool is_win = true, 
                OBJECT_TYPE type = OBJECT_TYPE::NONE);

    ~FinishState();
    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    bool compareTime();

    sf::Font title_font;
    sf::Text title;
    sf::Sprite background;

    std::unique_ptr<Button> button[2];
    int cur = -1;

    Context &m_context;
    Timer m_timer;
};

#endif /* SRC_GAME_STATE_FINISH */
