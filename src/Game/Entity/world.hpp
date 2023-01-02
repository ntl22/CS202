#ifndef SRC_GAME_ENTITY_WORLD
#define SRC_GAME_ENTITY_WORLD
#include "../../Framework/pch.hpp"

#include "animal.hpp"
#include "vehicle.hpp"
#include "road.hpp"
#include "people.hpp"
#include "pause.hpp"
#include "timer.hpp"

class World
{
public:
    World(Context &context, Timer& t);

    virtual ~World() = default;

    // void saveGame();
    // void loadGame();

    void handleEvent(const sf::Event &ev);
    void update();
    void draw();

    bool isWin();
    bool isDead();

private:
    People people;
    Road road;
    Timer& timer;

    bool is_win;

    Context &m_context;
};

#endif /* SRC_GAME_ENTITY_WORLD */
