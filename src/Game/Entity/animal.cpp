#include "animal.hpp"

Cat::Cat(TextureMap& map)
{
    texture = map.get(TEXTURES::cat1);
    sprite.setTexture(texture);
    sprite.scale(1.5, 1.5);
}

Chicken::Chicken(TextureMap& map)
{
    texture = map.get(TEXTURES::chicken);
    sprite.setTexture(texture);
    sprite.scale(1.5, 1.5);
}

