#include "vehicle.hpp"

void Vehicle::update(sf::Time dt,
                     unsigned velocity,
                     People &people,
                     TrafficLight &light,
                     sf::RenderWindow &window)
{
    sprite.move(velocity * 1.f * !light.isRed(), 0.f);
}

Truck::Truck(TextureMap &map)
{
    texture = map.get(TEXTURES::truck);
    sprite.setTexture(texture);
    sprite.scale(1.5, 1.5);
}

Car::Car(TextureMap &map)
{
    texture = map.get(TEXTURES::car);
    sprite.setTexture(texture);
    sprite.scale(1.5, 1.5);
}