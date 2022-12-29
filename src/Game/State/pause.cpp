#include "pause.hpp"

PauseState::PauseState(Context &context,
                       bool &exit_ref, bool &pause_ref)
    : m_context(context),
      is_exit(exit_ref),
      is_pause(pause_ref),
      font_pause(context.fonts->get(FONTS::Sansation))
{
    text_pause.setString("PAUSED");
    text_pause.setCharacterSize(100U);
    text_pause.setFont(font_pause);

    sf::Vector2u size = m_context.window->getSize();
    setCenterOrigin(text_pause, text_pause.getLocalBounds());

    text_pause.setPosition(size.x / 2.f, size.y / 2.f);
}

void PauseState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed)
    {
        is_exit = (ev.key.code == sf::Keyboard::Escape);

        if (ev.key.code == sf::Keyboard::P)
            is_pause = false;
    }
}

void PauseState::update(sf::Time dt) {}

void PauseState::draw()
{
    m_context.window->draw(text_pause);

    std::clog << "In PauseState" << std::endl;
}
