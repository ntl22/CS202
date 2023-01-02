#ifndef SRC_GAME_ENTITY_ROAD
#define SRC_GAME_ENTITY_ROAD
#include <vector>
#include <iostream>
#include <time.h>
#include <string>
#include "SFML/System/Clock.hpp"
#include "../../Framework/pch.hpp"
#include "obstacle.hpp"
#include "animal.hpp"
#include "Vehicle.hpp"

class Road
{
public:
    Road() = default;
    virtual ~Road() = default;
    void LoadLane(TextureMap& textures);
    virtual void drawRoad(sf::RenderWindow &window);
    virtual void update(const float velocity, sf::RenderWindow &window, People &people);
    virtual void setPos(int y, sf::RenderWindow &window);
    virtual float getBound();
    void updateLight();

private:
    std::vector<Road *> roads;
    sf::Sprite light;
    sf::Texture lightRed;
    sf::Texture lightGreen;
    bool checkLight;
};

class Lane : public Road
{
public:
    Lane() = default;
    Lane(int i, int &count, TextureMap& textures);
    ~Lane() = default;
    void drawRoad(sf::RenderWindow &window);
    void update(const float velocity, sf::RenderWindow &window, People &people);
    void setPos(int y, sf::RenderWindow &window);
    float getBound();

private:
    Obstacle *object;
    sf::Sprite lane;
    sf::Texture laneBg;
    LANE_TYPE type;
};
#endif /* SRC_GAME_ENTITY_ROAD */
