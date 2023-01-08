#ifndef SRC_GAME_ENTITY_WORLD
#define SRC_GAME_ENTITY_WORLD
#include "../../Framework/pch.hpp"

#include "player.hpp"
#include "light.hpp"
#include "road.hpp"

// TODO: Merge all entities

class World
{
public:
    void handleEvent(const sf::Event& ev);
    void draw(sf::RenderWindow& window);
    std::pair<STATUS, OBJECT_TYPE> update(sf::Time dt);

private:
};

#endif /* SRC_GAME_ENTITY_WORLD */
