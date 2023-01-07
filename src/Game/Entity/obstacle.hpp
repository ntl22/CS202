#ifndef SRC_GAME_ENTITY_OBSTACLE
#define SRC_GAME_ENTITY_OBSTACLE
#include "../../Framework/pch.hpp"

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

#endif /* SRC_GAME_ENTITY_OBSTACLE */
