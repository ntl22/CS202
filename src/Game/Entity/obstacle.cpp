#include "obstacle.hpp"

#include "player.hpp"

void Obstacle::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Obstacle::collisionProcedure(People &people)
{
    if (getBound().intersects(people.getReact()))
        people.status = STATUS::DEAD;
}

void Obstacle::update(sf::Time dt,
                      unsigned velocity,
                      People &people,
                      TrafficLight &light,
                      sf::RenderWindow &window)
{
    sprite.move(velocity * 1.f, 0.f);
}

sf::FloatRect Obstacle::getBound()
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Obstacle::getPos()
{
    return sprite.getPosition();
}

void Obstacle::setPos(int x, int y)
{
    sprite.setPosition(x * 1.f, y * 1.f);
}
