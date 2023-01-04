#ifndef SRC_GAME_ENTITY_WORLD
#define SRC_GAME_ENTITY_WORLD
#include "../../Framework/pch.hpp"

#include "road.hpp"
#include "light.hpp"
#include "player.hpp"
#include "collidable.hpp"
#include "timer.hpp"

class World
{
public:
    World(Timer &timer,
          Context &context,
          unsigned speed = 5,
          unsigned num = 5);

    void handleEvent(const sf::Event &ev);
    std::pair<STATUS, OBJECT_TYPE> update(sf::Time dt);
    void draw();

private:
    void saveGame(std::ofstream &fout);
    void loadGame(std::ifstream &fin);

    People player;
    Road road;
    TrafficLight light;

    Timer &m_timer;
    Context &m_context;

    friend class SaveState;
    friend class PlayingState;
};

#endif /* SRC_GAME_ENTITY_WORLD */
