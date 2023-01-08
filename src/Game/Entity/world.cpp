#include "world.hpp"

World::World(Context &context, Timer &timer, unsigned velocity)
    : m_context(context),
      light(context),
      player(context),
      clock(timer),
      road(context, velocity),
      guideFont(context.fonts->get(FONTS::visitor1))
{

    guide.setFont(guideFont);
    guide.setString("Arrow keys or W,A,S,D to move \nP to pause");
    guide.setCharacterSize(30U);
    guide.setPosition(5, context.window->getSize().y - guide.getGlobalBounds().height * 1.5f);
    guide.setOutlineThickness(2);
    guide.setOutlineColor(sf::Color(10, 150, 8));
}

void World::handleEvent(const sf::Event &ev)
{
    player.handleEvent(ev);
}

void World::draw()
{
    road.draw(*m_context.window);
    m_context.window->draw(guide);
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

void World::saveGame(std::ofstream &fout)
{
    player.saveGame(fout);
    light.saveGame(fout);
    road.saveGame(fout);
}

void World::loadGame(std::ifstream &fin)
{
    player.loadGame(fin);
    light.loadGame(fin);
    road.loadGame(fin, *m_context.textures);
}