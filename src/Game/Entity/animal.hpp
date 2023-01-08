#ifndef SRC_GAME_ENTITY_ANIMAL
#define SRC_GAME_ENTITY_ANIMAL
#include "../../Framework/pch.hpp"
#include "obstacle.hpp"

class Animal : public Obstacle
{
};

class Cat : public Animal
{
public:
	Cat(TextureMap &map);
};

class Chicken : public Animal
{
public:
	Chicken(TextureMap &map);
};

#endif /* SRC_GAME_ENTITY_ANIMAL */
