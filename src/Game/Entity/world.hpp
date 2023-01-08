#ifndef SRC_GAME_ENTITY_WORLD
#define SRC_GAME_ENTITY_WORLD
#include "../../Framework/pch.hpp"

#include "player.hpp"
#include "light.hpp"
#include "road.hpp"
#include "timer.hpp"

class World
{
public:
    World(Context &context, Timer &timer, unsigned velocity);

    void handleEvent(const sf::Event &ev);
    void draw();
    std::pair<STATUS, OBJECT_TYPE> update(sf::Time dt);

private:
    void saveGame(std::ofstream &fout);
    void loadGame(std::ifstream &fin);

    Road road;
    People player;
    TrafficLight light;
    sf::Time delta;

    Timer &clock;

    Context &m_context;

    sf::Text guide;
    sf::Font guideFont;

    friend class SaveState;
    friend class PlayingState;
};

#endif /* SRC_GAME_ENTITY_WORLD */
