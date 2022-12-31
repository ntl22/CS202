#ifndef SRC_GAME_ENTITY_ROAD
#define SRC_GAME_ENTITY_ROAD
#include <vector>
#include <iostream>
#include <time.h>
#include <string>

#include "../../Framework/pch.hpp"
#include "obstacle.hpp"
#include "animal.hpp"
#include "Vehicle.hpp"

class Road
{
public:
    Road() = default;
    void LoadLane();
    virtual void drawRoad(sf::RenderWindow &window);
    virtual void update(const float velocity, sf::RenderWindow &window);
    virtual void setPos(int y, sf::RenderWindow &window);
    virtual float getBound();

private:
    std::vector<Road *> roads;
};

class Lane : public Road
{
public:
    Lane() = default;
    Lane(int i);

    void drawRoad(sf::RenderWindow &window);
    void update(const float velocity, sf::RenderWindow &window);
    void setPos(int y, sf::RenderWindow &window);
    float getBound();

private:
    Obstacle *object;
    sf::Sprite lane;
    sf::Texture laneBg;
    LANE_TYPE type;
};
#endif