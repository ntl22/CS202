#ifndef SRC_GAME_STATE_LOADING
#define SRC_GAME_STATE_LOADING
#include "../../Framework/pch.hpp"

class LoadingTask;

class LoadingState : public State
{
public:
    LoadingState(Context &context);

    void handleEvent(const sf::Event &ev);
    void update(sf::Time dt);
    void draw();

private:
    sf::Font font;
    sf::Text loading_text;

    Context& m_context;

    std::unique_ptr<LoadingTask> task;
};

#endif /* SRC_GAME_STATE_LOADING */
