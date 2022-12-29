#ifndef SRC_GAME_STATE_SPLASH
#define SRC_GAME_STATE_SPLASH
#include "../../Framework/pch.hpp"

class SplashTask;

class SplashState : public State
{
public:
    SplashState(Context& context);

    void handleEvent(const sf::Event &ev);
    void update(sf::Time dt);
    void draw();

private:
    sf::Font font;
    sf::Text text;

    std::unique_ptr<SplashTask> task;

    Context& m_context;
};

#endif /* SRC_GAME_STATE_SPLASH */
