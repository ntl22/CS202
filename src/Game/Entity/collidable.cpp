#include "collidable.hpp"

void Obstacle::collisionProcedure(People &people)
{
    if (getBound().intersects(people.getReact()))
        people.status = STATUS::DEAD;
}

Animal::Animal(OBJECT_TYPE type, TextureMap &map)
{
    switch (type)
    {
    case OBJECT_TYPE::CAT:
        animalTex = map.get(TEXTURES::cat1);
        break;
    case OBJECT_TYPE::CHICKEN:
        animalTex = map.get(TEXTURES::chicken);
        break;
    }
    animal.setTexture(animalTex);
    animal.scale(1.5, 1.5);
}
Vehicle::Vehicle(OBJECT_TYPE type, TextureMap &map)
{
    switch (type)
    {
    case OBJECT_TYPE::TRUCK:
        vehicleTex = map.get(TEXTURES::truck);
        break;
    case OBJECT_TYPE::CHICKEN:
        vehicleTex = map.get(TEXTURES::car);
        break;
    }
    vehicle.setTexture(vehicleTex);
    vehicle.scale(1.5, 1.5);
}
void Vehicle::draw(sf::RenderWindow &window)
{
    window.draw(this->vehicle);
}

void Animal::draw(sf::RenderWindow &window)
{
    window.draw(this->animal);
}

void Animal::update(sf::Time dt, unsigned velocity, People &people, sf::RenderWindow &window)
{

    this->animal.move(velocity * 1.f, 0.f);
}

void Vehicle::update(sf::Time dt, unsigned velocity, People &people, sf::RenderWindow &window)
{

    this->vehicle.move(velocity * 1.f, 0.f);
}

sf::FloatRect Animal::getBound()
{
    return animal.getGlobalBounds();
}

sf::FloatRect Vehicle::getBound()
{
    return vehicle.getGlobalBounds();
}

void Animal::setPos(int x, int y)
{
    this->animal.setPosition(x * 1.f, y * 1.f);
}

void Vehicle::setPos(int x, int y)
{
    this->vehicle.setPosition(x * 1.f, y * 1.f);
}

sf::Vector2f Animal::getPos()
{
    return this->animal.getPosition();
}
sf::Vector2f Vehicle::getPos()
{
    return this->vehicle.getPosition();
}

void ListOfObstacle::update(sf::Time dt, unsigned velocity, People &people, sf::RenderWindow &window)
{
    size_t i, size = list.size();

    for (i = 0; i < size; i++)
    {
        list[i]->update(dt, velocity, people, window);

        list[i]->collisionProcedure(people);

        if (people.getPlayingStatus() == STATUS::DEAD)
            break;

        if (list[i]->getBound().left > window.getSize().x)
        {
            int tmp;
            if (i == 0)
            {
                if (list.back()->getPos().x > 0)
                {
                    tmp = 0 - (rand() % 300 + 200) - (velocity * 12);
                    list[i]->setPos(tmp, (unsigned)list[i]->getPos().y);
                }
                else
                {
                    tmp = (int)(list.back()->getPos().x - (rand() % 300 + 200) - (velocity * 12));
                    list[i]->setPos(tmp, (unsigned)list[i]->getPos().y);
                }
            }
            else
            {
                tmp = (int)(list[i - 1]->getPos().x - (rand() % 300 + 200) - (velocity * 12));
                list[i]->setPos(tmp, (unsigned)list[i]->getPos().y);
            }
        }
    }
}
