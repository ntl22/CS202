#ifndef SRC_GAME_STATE_LOAD
#define SRC_GAME_STATE_LOAD
#include "../../Framework/pch.hpp"

class LoadState : public State
{
public:
    LoadState(Context &context);

    void handleEvent(const sf::Event &ev);
    void update(sf::Time dt);
    void draw();

private:
    void loadGame();

    sf::Sprite background;

    sf::Text title;
    sf::Text input_here;

    sf::Text invalid;

    sf::RectangleShape input;
    std::string file_name;
    sf::Text file_to_gui;
    const unsigned capacity;

    bool folder, exist;

    Context &m_context;
};

#endif /* SRC_GAME_STATE_LOAD */
