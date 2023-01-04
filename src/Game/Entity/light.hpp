#ifndef SRC_GAME_ENTITY_LIGHT
#define SRC_GAME_ENTITY_LIGHT
#include "collidable.hpp"

class TrafficLight
{
public:
    TrafficLight(Context &context, sf::Time delta = sf::seconds(3.f));

    void updateRed();

    void updateGreen();

    bool isRed() const;

private:
    sf::Sprite light_sprite;


    const sf::Time between;
    
    sf::Time last_update;

    bool is_red;

    Context &m_context;

    friend class World;
};

#endif /* SRC_GAME_ENTITY_LIGHT */
