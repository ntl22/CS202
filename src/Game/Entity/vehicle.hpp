#ifndef SRC_GAME_ENTITY_VEHICLE
#define SRC_GAME_ENTITY_VEHICLE
#include "obstacle.hpp"

// TODO: Implement Vehicle type

class Vehicle : public Obstacle
{
public:
    void update(sf::Time dt,
        unsigned velocity,
        People& people,
        TrafficLight& light,
        sf::RenderWindow& window) override;
};

class Truck : public Vehicle
{
public:
    Truck(TextureMap& map);
};

class Car : public Vehicle
{
    Car(TextureMap& map);
};
#endif /* SRC_GAME_ENTITY_VEHICLE */
