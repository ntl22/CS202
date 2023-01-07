#include "playing.hpp"

#include "pause.hpp"
#include "finish.hpp"

class LevelUpState : public State
{
public:
    LevelUpState(Context &context, const int &level)
        : next_level("Level " + std::to_string(level) + " is next!",
                     context.fonts->get(FONTS::visitor1), 70U),
          m_context(context)
    {
        next_level.setFillColor(sf::Color::Green);
        setCenterOrigin(next_level, next_level.getLocalBounds());
        next_level.setPosition(context.window->getView().getCenter());
    }

    void handleEvent(const sf::Event &ev)
    {
        if (ev.type == sf::Event::KeyPressed &&
            ev.key.code == sf::Keyboard::Enter)
        {
            m_context.musics->pause(false);
            m_context.states->pop();
        }
    }

    void update(sf::Time dt) {}

    void draw()
    {
        m_context.window->draw(next_level);
    }

private:
    sf::Text next_level;

    Context &m_context;
};

PlayingState::PlayingState(Context &context)
    : m_context(context),
      is_exit(false),
      is_pause(false),
      cur_level(1),
      MAX_LEVEL(5)
{
}

void PlayingState::handleEvent(const sf::Event &ev)
{
}

void PlayingState::update(sf::Time dt)
{
}

void PlayingState::draw()
{
}
