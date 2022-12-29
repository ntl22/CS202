#include "playing.hpp"

PlayingState::PlayingState(std::shared_ptr<Context> context)
    : m_context(context), is_exit(false), is_pause(false)
{
    pause = std::make_unique<PauseState>(context, is_exit, is_pause);
    cat.spawn(200, OBJECT_TYPE::CAT);
    dog.spawn(400, OBJECT_TYPE::DOG);
}

void PlayingState::handleEvent(const sf::Event &ev)
{
    if (is_pause)
        pause->handleEvent(ev);
    else
    {
        people.handleEvent(ev);
        if (ev.type == sf::Event::KeyPressed)
        {
            if (ev.key.code == sf::Keyboard::P)
                is_pause = true;
        }
    }
}

void PlayingState::update(sf::Time dt)
{
    cat.update(5, *(m_context->window));
    dog.update(5, *(m_context->window));
    if (is_exit)
    {

        m_context->states->pop();
    }
    else if (is_pause)
    {
        pause->update(dt);
    }
}

void PlayingState::draw()
{
    if (is_pause)
        pause->draw();
    else
    {
        std::clog << "In PlayingState" << std::endl;
        people.draw(*(m_context->window));
        cat.Render(*(m_context->window));
        dog.Render(*(m_context->window));
    }
}

PlayingState::PauseState::PauseState(std::shared_ptr<Context> context,
                                     bool &exit_ref, bool &pause_ref)
    : m_context(context),
      is_exit(exit_ref),
      is_pause(pause_ref),
      font_pause(context->fonts->get(FONTS::Sansation))
{
    text_pause.setString("PAUSED");
    text_pause.setCharacterSize(100U);
    text_pause.setFont(font_pause);

    sf::Vector2u size = m_context->window->getSize();
    setCenterOrigin(text_pause, text_pause.getLocalBounds());

    text_pause.setPosition(size.x / 2.f, size.y / 2.f);
}

void PlayingState::PauseState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed)
    {
        is_exit = (ev.key.code == sf::Keyboard::Escape);

        if (ev.key.code == sf::Keyboard::P)
            is_pause = false;
    }
}

void PlayingState::PauseState::update(sf::Time dt) {}

void PlayingState::PauseState::draw()
{
    m_context->window->draw(text_pause);

    std::clog << "In PauseState" << std::endl;
}
