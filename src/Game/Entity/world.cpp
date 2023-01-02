#include "world.hpp"

World::World(Context &context, Timer &t)
    : m_context(context),
      is_win(false),
      people(*context.window, *context.textures),
      timer(t)
{
    road.LoadLane(*m_context.textures);
    road.setPos(0, *(m_context.window));
}

void World::handleEvent(const sf::Event &ev)
{
    people.handleEvent(ev);
}

void World::update()
{
    timer.update();
    road.update(5, *(m_context.window), people);
}

void World::draw()
{
    road.drawRoad(*(m_context.window));
    people.draw(*(m_context.window));
    timer.draw(*(m_context.window));
}

bool World::isWin()
{
    return people.isFinish();
}

bool World::isDead()
{
    return people.get_dead();
}
