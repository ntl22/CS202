#ifndef SRC_GAME_STATE_SAVE
#define SRC_GAME_STATE_SAVE
#include "../../Framework/pch.hpp"

class SaveState : public State
{
public:
    SaveState(Context& context, std::function<void(std::string)>& f_ref);

    void handleEvent(const sf::Event& ev);
    void update(sf::Time dt);
    void draw();

private:
    void saveGame();
    std::function<void(std::string)>& save;

    sf::Text title;
    sf::Text input_here;
    sf::Text invalid;
    sf::Text go_back;

    sf::RectangleShape input;
    std::string file_name;
    sf::Text file_to_gui;
    const unsigned capacity;

    Context& m_context;
};

#endif /* SRC_GAME_STATE_SAVE */
