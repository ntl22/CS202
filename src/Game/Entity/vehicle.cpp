#include "vehicle.hpp"

Truck::Truck(TextureMap& map)
{
    texture = map.get(TEXTURES::truck);
    sprite.setTexture(texture);
    sprite.scale(1.5, 1.5);
}

Car::Car(TextureMap& map)
{
    texture = map.get(TEXTURES::car);
    sprite.setTexture(texture);
    sprite.scale(1.5, 1.5);
}