#ifndef SRC_GAME_STATE_MENU
#define SRC_GAME_STATE_MENU
#include "../../Framework/pch.hpp"

class MenuState : public State
{
public:
    MenuState(std::shared_ptr<Context> context);

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    sf::Font title_font;
    sf::Text title;
    sf::Sprite background;

    std::unique_ptr<Button> button[3];
    int cur = -1;

    std::shared_ptr<Context> context;
};

#endif /* SRC_GAME_STATE_MENU */
