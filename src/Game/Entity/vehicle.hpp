#ifndef SRC_GAME_ENTITY_VEHICLE
#define SRC_GAME_ENTITY_VEHICLE

#include <vector>
#include <iostream>
#include <time.h>
#include "obstacle.hpp"
#include "../../Framework/pch.hpp"

class Vehicle : public Obstacle
{
private:
    // sf::Vector2f aniVelocity;
    std::vector<Vehicle *> vehicles;

public:
    Vehicle() = default;
    void spawn(float y, const OBJECT_TYPE type);
    virtual sf::Vector2f getPos();
    virtual void Render(sf::RenderWindow &window);
    virtual void update(const float velocity, sf::RenderWindow &window, People& people);
    virtual sf::FloatRect GetBound();
    virtual void setPos(int x, int y);
};

class Truck : public Vehicle
{
public:
    sf::Vector2f getPos();
    void setPos(int x, int y);

    Truck() = default;
    Truck(float x, float y, int i)
    {
        this->innitTexture(i);
        this->truck.setPosition(x, y);
    }
    void innitTexture(int i);
    void Render(sf::RenderWindow &window);
    void update(const float velocity, sf::RenderWindow &window, People& people);
    sf::FloatRect GetBound();

private:
    sf::Sprite truck;
    sf::Texture truckTexture;

private:
};
class Car : public Vehicle
{
public:
    void setPos(int x, int y);
    void setStartPosition(float x, float y);
    sf::Vector2f getVelocity();
    sf::Vector2f getPos();
    Car() = default;
    Car(float x, float y)
    {
        this->innitTexture();
        this->car.setPosition(x, y);
    }
    void innitTexture();
    void update(const float velocity, sf::RenderWindow &window, People& people);
    void Render(sf::RenderWindow &window);
    sf::FloatRect GetBound();

public:
    sf::Sprite car;
    sf::Texture carTexture;

private:
};
#endif // SRC_INCLUDES_ANIMAL_ANIMAL_HPP