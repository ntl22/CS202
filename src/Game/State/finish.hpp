#ifndef SRC_GAME_STATE_FINISH
#define SRC_GAME_STATE_FINISH
#include "../../Framework/pch.hpp"

class FinishState : public State {
public:
	FinishState(Context& context);

	~FinishState();
	    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    sf::Font title_font;
    sf::Text title;
    sf::Sprite background;

    std::unique_ptr<Button> button[2];
    int cur = -1;

    Context& m_context;
};

#endif /* SRC_GAME_STATE_FINISH */