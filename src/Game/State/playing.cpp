#include "playing.hpp"

PlayingState::PlayingState(Context &context)
    : m_context(context),
      people(People(*context.window)),
      is_exit(false),
      is_pause(false),
      pause(PauseState(context, is_exit, is_pause))
{
    ani->spawn(200, OBJECT_TYPE::CHICKEN);
    vehi->spawn(400, OBJECT_TYPE::CAR);
    m_context.musics->stop();
}

void PlayingState::handleEvent(const sf::Event &ev)
{
    if (is_pause)
        pause.handleEvent(ev);
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
    if (is_exit)
    {
        m_context.states->pop();
        m_context.musics->play(MUSICS::intro);
    }
    else if (is_pause)
    {
        pause.update(dt);
    }
    else
    {
        ani->update(5, *(m_context.window));
        vehi->update(5, *(m_context.window));
    }
}

void PlayingState::draw()
{
    if (is_pause)
        pause.draw();
    else
    {
        std::clog << "In PlayingState" << std::endl;
        people.draw(*(m_context.window));
        ani->Render(*(m_context.window));
        vehi->Render(*(m_context.window));
    }
}
