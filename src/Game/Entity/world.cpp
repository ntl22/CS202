#include "world.hpp"

World::World(Context &context, Timer &timer)
    : m_context(context),
      light(context),
      player(context),
      clock(timer)
{
}

void World::handleEvent(const sf::Event &ev)
{
    player.handleEvent(ev);
}

void World::draw()
{

    light.draw(*m_context.window);
    player.draw(*m_context.window);
    clock.draw(*m_context.window);
}

std::pair<STATUS, OBJECT_TYPE> World::update(sf::Time dt)
{
    if (light.updateTime(clock.update()) >= light.getDelta())
    {
        light.isRed() ? light.updateGreen() : light.updateRed();
    }

    player.update(dt);
    return {player.getPlayingStatus(), OBJECT_TYPE::NONE};
}
