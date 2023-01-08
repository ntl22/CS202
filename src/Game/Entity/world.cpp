#include "world.hpp"

void World::handleEvent(const sf::Event &ev) {}

void World::draw(sf::RenderWindow &window){}

std::pair<STATUS, OBJECT_TYPE> World::update(sf::Time dt)
{
    return {STATUS::WIN, OBJECT_TYPE::ANIMAL};
}
