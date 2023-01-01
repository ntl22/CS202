#include "playing.hpp"
#include "finish.hpp"

PlayingState::PlayingState(Context &context)
    : m_context(context),
      people(*context.window, *context.textures),
      is_exit(false),
      timer(context)
{
    m_context.musics->pause(true);
    srand((unsigned)time(NULL));
    a.LoadLane(*m_context.textures);
    a.setPos(0, *(m_context.window));
    // a->spawn(0, OBJECT_TYPE::CHICKEN);
    m_context.musics->setLoop(true);
    m_context.musics->play(MUSICS::playing);
}

void PlayingState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed)
    {
        if (ev.key.code == sf::Keyboard::P)
        {
            m_context.musics->pause(true);
            m_context.states->push(std::make_unique<PauseState>(m_context, is_exit));
        }
    }
    people.handleEvent(ev);
}

void PlayingState::update(sf::Time dt)
{
    if (is_exit)
    {
        m_context.states->pop();
        m_context.musics->play(MUSICS::intro);
    }
    else
    {
        a.update(5, *(m_context.window), people);
        if (people.get_dead() || people.isFinish())
            m_context.states->push(std::make_unique<FinishState>(m_context), true);
    }
}

void PlayingState::draw()
{
    if (!is_exit)
    {
        a.drawRoad(*(m_context.window));
        people.draw(*(m_context.window));
        timer.draw(*(m_context.window));
    }
}
