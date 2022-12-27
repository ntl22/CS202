#ifndef SRC_GAME_ENTITY_STATE
#define SRC_GAME_ENTITY_STATE
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

#include <memory>

struct State
{
    /**
     * Prerequisite task of a state
     */

    virtual void handleEvent(const sf::Event& ev) = 0;
    virtual void update(sf::Time dt) = 0;
    virtual void draw() = 0;
};

#endif /* SRC_GAME_ENTITY_STATE */
