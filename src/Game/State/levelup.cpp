#include "levelup.hpp"

#include "../Entity/timer.hpp"

LevelUpState::LevelUpState(Context &context, Timer &timer, const int &level)
    : next_level("Level " + std::to_string(level) + " is next!",
                 context.fonts->get(FONTS::visitor1), 70U),
      press_enter("Press Enter to continue...",
                  context.fonts->get(FONTS::visitor1), 30U),
      clock(timer),
      m_context(context)
{
    m_context.musics->pause(true);
    next_level.setFillColor(sf::Color::Green);
    setCenterOrigin(next_level, next_level.getLocalBounds());
    next_level.setPosition(context.window->getView().getCenter() - sf::Vector2f(0, 50.f));

    setCenterOrigin(press_enter, press_enter.getLocalBounds());
    press_enter.setPosition(context.window->getView().getCenter() + sf::Vector2f(0, 50.f));

    m_context.sounds->play(SOUNDBUFFERS::levelup);
}

LevelUpState::~LevelUpState()
{
    clock.exitPauseState();
    m_context.musics->pause(false);
}

void LevelUpState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed &&
        ev.key.code == sf::Keyboard::Enter)
    {
        m_context.states->pop();
    }
}

void LevelUpState::update(sf::Time dt) {}

void LevelUpState::draw()
{
    m_context.window->draw(next_level);
    m_context.window->draw(press_enter);
}
