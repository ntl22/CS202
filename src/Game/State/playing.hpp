#ifndef SRC_GAME_STATE_PLAYING
#define SRC_GAME_STATE_PLAYING
#include "../../Framework/pch.hpp"
#include "../Entity/people.hpp"
#include "../Entity/animal.hpp"

class PlayingState : public State
{
public:
    PlayingState(std::shared_ptr<Context> context);

    void handleEvent(const sf::Event &ev) override;
    void update(sf::Time dt) override;
    void draw() override;

private:
    std::shared_ptr<Context> m_context;
    People people;
    Animal cat;
    Animal dog;
    bool is_exit, is_pause;

    class PauseState : public State
    {
    public:
        PauseState(std::shared_ptr<Context> context,
                   bool &exit_ref, bool &pause_ref);

        void handleEvent(const sf::Event &ev) override;
        void update(sf::Time dt) override;
        void draw() override;

    private:
        bool &is_exit, &is_pause;

        std::shared_ptr<Context> m_context;

        sf::Text text_pause;
        sf::Font font_pause;
    };

    std::unique_ptr<PauseState> pause;
};

#endif /* SRC_GAME_STATE_PLAYING */
