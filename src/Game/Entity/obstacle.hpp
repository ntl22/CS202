#ifndef SRC_GAME_ENTITY_OBSTACLE
#define SRC_GAME_ENTITY_OBSTACLE
#include "../../Framework/pch.hpp"

#include "player.hpp"

class People;
class TrafficLight;

class Obstacle
{
public:
    virtual ~Obstacle() = default;

    void draw(sf::RenderWindow &window);
    virtual void update(sf::Time dt,
                        unsigned velocity,
                        People &people,
                        TrafficLight &light,
                        sf::RenderWindow &window);
    sf::FloatRect getBound();
    sf::Vector2f getPos();
    void setPos(int x, int y);
    void collisionProcedure(People &people);

protected:
    sf::Texture texture;
    sf::Sprite sprite;
};

class Animal : public Obstacle
{
};

class Cat : public Animal
{
public:
    Cat(TextureMap &map)
    {
        texture = map.get(TEXTURES::cat1);
        sprite.setTexture(texture);
        sprite.scale(1.5, 1.5);
    }
};

class Chicken : public Animal
{
public:
    Chicken(TextureMap &map)
    {
        texture = map.get(TEXTURES::chicken);
        sprite.setTexture(texture);
        sprite.scale(1.5, 1.5);
    }
};

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
    Truck(TextureMap &map)
    {
        texture = map.get(TEXTURES::truck);
        sprite.setTexture(texture);
        sprite.scale(1.5, 1.5);
    }
};

class Car : public Vehicle
{
public:
    Car(TextureMap &map)
    {
        texture = map.get(TEXTURES::car);
        sprite.setTexture(texture);
        sprite.scale(1.5, 1.5);
    }
};

#endif /* SRC_GAME_ENTITY_OBSTACLE */
