#include "playing.hpp"

PlayingState::PlayingState(Context &context)
    : m_context(context),
      people(People(*context.window)),
      is_exit(false),
      is_pause(false),
      pause(PauseState(context, is_exit, is_pause))
{
    a.LoadLane();
    a.setPos(0, *(m_context.window));
    // a->spawn(0, OBJECT_TYPE::CHICKEN);
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
        a.update(5, *(m_context.window));
    }
}

void PlayingState::draw()
{
    if (is_pause)
        pause.draw();
    else
    {
        std::clog << "In PlayingState" << std::endl;
        a.drawRoad(*(m_context.window));
        people.draw(*(m_context.window));
    }
}
