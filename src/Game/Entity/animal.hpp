#ifndef SRC_GAME_ENTITY_ANIMAL
#define SRC_GAME_ENTITY_ANIMAL
#include <vector>
#include <iostream>
#include <time.h>
#include <string>
#include "obstacle.hpp"
#include "../../Framework/pch.hpp"

class Animal : public Obstacle
{
private:
    // sf::Vector2f aniVelocity;
    std::vector<Animal *> animals;

public:
    Animal() = default;
    void spawn(float y, const OBJECT_TYPE type);
    virtual sf::Vector2f getPos();
    virtual void Render(sf::RenderWindow &window);
    virtual void update(const float velocity, sf::RenderWindow &window, People& people);
    virtual sf::FloatRect GetBound();
    virtual void setPos(int x, int y);
};

class Cat : public Animal
{
public:
    sf::Vector2f getPos();

    Cat() = default;
    Cat(float x, float y, int i)
    {
        this->innitTexture(i);
        this->cat.setPosition(x, y);
    }
    void innitTexture(int i);
    void Render(sf::RenderWindow &window);
    void update(const float velocity, sf::RenderWindow &window, People& people);
    sf::FloatRect GetBound();
    void setPos(int x, int y);

private:
    sf::Sprite cat;
    sf::Texture catTexture;

private:
};
class Dog : public Animal
{
public:
    void setVelocity(float x, float y);
    void setStartPosition(float x, float y);
    sf::Vector2f getVelocity();
    sf::Vector2f getPos();
    Dog() = default;
    Dog(float x, float y)
    {
        this->innitTexture();
        this->dog.setPosition(x, y);
    }
    void innitTexture();
    void update(const float velocity, sf::RenderWindow &window, People& people);
    void Render(sf::RenderWindow &window);
    sf::FloatRect GetBound();
    void setPos(int x, int y);

public:
    sf::Sprite dog;
    sf::Texture dogTexture;

private:
};
#endif // SRC_INCLUDES_ANIMAL_ANIMAL_HPP