#include "levelup.hpp"

LevelUpState::LevelUpState(Context &context, Timer &timer, const int &level)
    : next_level("Level " + std::to_string(level) + " is next!",
                 context.fonts->get(FONTS::visitor1), 70U),
      press_enter("Press Enter to continue...",
                 context.fonts->get(FONTS::visitor1), 30U),
      m_timer(timer),
      m_context(context)
{
    next_level.setFillColor(sf::Color::Green);
    setCenterOrigin(next_level, next_level.getLocalBounds());
    setCenterOrigin(press_enter, press_enter.getLocalBounds());
    next_level.setPosition(context.window->getView().getCenter() - sf::Vector2f(0, 30));
    press_enter.setPosition(context.window->getView().getCenter() + sf::Vector2f(0, 40));
    context.sounds->play(SOUNDBUFFERS::levelup);
}

void LevelUpState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed &&
        ev.key.code == sf::Keyboard::Enter)
    {
        m_context.musics->pause(false);
        m_context.states->pop();
        m_timer.exitPauseState();
    }
}

void LevelUpState::update(sf::Time dt) {}

void LevelUpState::draw()
{
    m_context.window->draw(next_level);
    m_context.window->draw(press_enter);
}
