#include "world.hpp"

World::World(Context &context, Timer &timer, unsigned velocity)
    : m_context(context),
      light(context),
      player(context),
      clock(timer),
      road(context, velocity) {}

void World::handleEvent(const sf::Event &ev)
{
    player.handleEvent(ev);
}

void World::draw()
{
    road.draw(*m_context.window);
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
    road.update(dt, player, light, *m_context.window);
    return {player.getPlayingStatus(), road.getType()};
}

void World::saveGame(std::ofstream& fout)
{
    player.saveGame(fout);
    light.saveGame(fout);
    //road.saveGame(fout);
}

void World::loadGame(std::ifstream& fin)
{
    player.loadGame(fin);
    light.loadGame(fin);
    //road.loadGame(fin);
}