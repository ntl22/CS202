#ifndef SRC_GAME_ENTITY_WORLD
#define SRC_GAME_ENTITY_WORLD
#include "../../Framework/pch.hpp"

#include "animal.hpp"
#include "vehicle.hpp"
#include "road.hpp"
#include "people.hpp"
#include "pause.hpp"
#include "timer.hpp"

class World : public State
{
public:
    World() = default;
    World(Context &context);

    // void saveGame();
    // void loadGame();

    void handleEvent(const sf::Event &ev);
    void update();
    void draw();

    // bool isWin() const;

private:
    void levelUp();
    void resetGame();

    People people;
    Road road;
    Timer timer;

    Context &m_context;

    bool is_exit;
};

#endif /* SRC_GAME_ENTITY_WORLD */
