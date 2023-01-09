#ifndef SRC_GAME_STATE_MENU
#define SRC_GAME_STATE_MENU
#include "../../Framework/pch.hpp"

class MenuState : public State
{
public:
    MenuState(Context &context);

    ~MenuState();

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    sf::Font title_font;
    sf::Text title;
    sf::Sprite background;
    std::string music;
    std::unique_ptr<Button> button[4];
    int cur = -1;
    bool update_str;
    Context &m_context;
};

#endif /* SRC_GAME_STATE_MENU */
