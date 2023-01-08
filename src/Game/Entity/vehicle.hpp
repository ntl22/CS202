#ifndef SRC_GAME_ENTITY_VEHICLE
#define SRC_GAME_ENTITY_VEHICLE
#include "../../Framework/pch.hpp"

#include "obstacle.hpp"
#include "light.hpp"

class Vehicle : public Obstacle
{
public:
    void update(sf::Time dt,
                unsigned velocity,
                People &people,
                TrafficLight &light,
                sf::RenderWindow &window) override;
};

class Truck : public Vehicle
{
public:
    Truck(TextureMap &map);
};

class Car : public Vehicle
{
public:
    Car(TextureMap &map);
};
#endif /* SRC_GAME_ENTITY_VEHICLE */
