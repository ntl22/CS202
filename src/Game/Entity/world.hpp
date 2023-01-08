#ifndef SRC_GAME_ENTITY_WORLD
#define SRC_GAME_ENTITY_WORLD
#include "../../Framework/pch.hpp"

#include "player.hpp"
#include "light.hpp"
#include "road.hpp"
#include "timer.hpp"

// TODO: Merge all entities

class World
{
public:
    World(Context &context, Timer &timer, unsigned velocity);

    void handleEvent(const sf::Event &ev);
    void draw();
    std::pair<STATUS, OBJECT_TYPE> update(sf::Time dt);

private:
    Road road;
    People player;
    TrafficLight light;
    sf::Time delta;

    Timer &clock;

    Context &m_context;
};

#endif /* SRC_GAME_ENTITY_WORLD */
