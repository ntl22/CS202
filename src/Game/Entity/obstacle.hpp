#ifndef SRC_GAME_ENTITY_OBSTACLE
#define SRC_GAME_ENTITY_OBSTACLE
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "../../Framework/pch.hpp"
#include "people.hpp"

class Obstacle
{
public:
    virtual void spawn(float y, const OBJECT_TYPE type) = 0;
    virtual sf::Vector2f getPos() = 0;
    virtual void Render(sf::RenderWindow &window) = 0;
    virtual void update(const float velocity, sf::RenderWindow &window, People& people) = 0;
    virtual sf::FloatRect GetBound() = 0;
    virtual void setPos(int x, int y) = 0;
    virtual OBJECT_TYPE getType() = 0;
};

#endif /* SRC_GAME_ENTITY_OBJECT */