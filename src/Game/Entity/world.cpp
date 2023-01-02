#include "world.hpp"
#include "finish.hpp"

World::World(Context &context)
    : m_context(context),
      people(*context.window, *context.textures),
      is_exit(false),
      timer(context)
{
    m_context.musics->pause(true);
    srand((unsigned)time(NULL));
    road.LoadLane(*m_context.textures);
    road.setPos(0, *(m_context.window));
    m_context.musics->setLoop(true);
    m_context.musics->play(MUSICS::playing);
}

void World::handleEvent(const sf::Event &ev)
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

void World::update()
{
    if (is_exit)
    {
        m_context.states->pop();
        m_context.musics->play(MUSICS::intro);
    }
    else
    {
        road.update(5, *(m_context.window), people);

        if (people.get_dead() || people.isFinish())
            m_context.states->push(std::make_unique<FinishState>(m_context), true);
    }
}

void World::draw()
{
    if (!is_exit)
    {
        road.drawRoad(*(m_context.window));
        people.draw(*(m_context.window));
        timer.draw(*(m_context.window));
    }
}
