#ifndef SRC_GAME_STATE_FINISH
#define SRC_GAME_STATE_FINISH
#include "../../Framework/pch.hpp"

#include "../Entity/timer.hpp"

class FinishState : public State
{
public:
    FinishState(Context &context, sf::Time time, OBJECT_TYPE type = OBJECT_TYPE::NONE);

    ~FinishState();
    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    void updateHighscore(OBJECT_TYPE type);

    std::string formatTime();

    sf::Font title_font;
    sf::Text title, highscore;
    sf::Sprite background;

    std::unique_ptr<Button> button[2];
    int cur = -1;

    sf::Time final_time;

    Context &m_context;
};

#endif /* SRC_GAME_STATE_FINISH */