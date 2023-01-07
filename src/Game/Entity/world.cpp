#include "world.hpp"

World::World(Timer &timer,
             Context &context,
             unsigned speed,
             unsigned num)
    : player(context),
      road(context, speed),
      light(context),
      m_timer(timer),
      m_context(context),
      guideFont(context.fonts->get(FONTS::visitor1))
{
    light.light_sprite.setPosition({m_context.window->getSize().x -
                                        light.light_sprite.getLocalBounds().width - 10.f,
                                    10});
    guide.setFont(guideFont);
    guide.setString("Arrow key to move \nP to pause");
    guide.setCharacterSize(30U);
    guide.setPosition(5, context.window->getSize().y - guide.getGlobalBounds().height * 1.5f);
}

void World::handleEvent(const sf::Event &ev)
{
    player.handleEvent(ev);
}

void World::draw()
{
    road.draw(*m_context.window);
    m_context.window->draw(light.light_sprite);
    player.draw(*m_context.window);
    m_timer.draw(*m_context.window);
    m_context.window->draw(guide);
}

std::pair<STATUS, OBJECT_TYPE> World::update(sf::Time dt)
{
    if ((light.last_update += m_timer.update()) >= light.between)
    {
        light.is_red ? light.updateGreen() : light.updateRed();
        light.last_update = sf::Time::Zero;
    }

    m_timer.update();
    player.update(dt);
    road.update(dt, player, light, *m_context.window);

    return {player.getPlayingStatus(), road.getType()};
}

void World::saveGame(std::ofstream &fout)
{
    player.saveGame(fout);
    light.saveGame(fout);
    //road.saveGame(fout);
}

void World::loadGame(std::ifstream &fin)
{
    player.loadGame(fin);
    light.loadGame(fin);
    //road.loadGame(fin);
}
