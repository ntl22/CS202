#include "vehicle.hpp"

void Vehicle::setPos(int x, int y)
{
    return;
}
void Truck::setPos(int x, int y)
{
    this->truck.setPosition(x, y);
}
void Car::setPos(int x, int y)
{
    this->car.setPosition(x, y);
}

void Truck::innitTexture(int i)
{

    if (truckTexture.loadFromFile("assets/images/car1.png"))
    {
        std::cout << "Fail texture";
    }

    this->truck.setTexture(truckTexture);
    this->truck.scale(0.5, 0.5);
}
void Car::innitTexture()
{
    if (carTexture.loadFromFile("assets/images/truck1.png"))
    {
        std::cout << "Fail texture";
    }
    this->car.setTexture(carTexture);
    this->car.scale(0.5, 0.5);
}

void Vehicle::spawn(float y, const OBJECT_TYPE type)
{
    if (type == OBJECT_TYPE::TRUCK)
    {
        int k = 0;
        for (int i = 0; i < 5; i++)
        {

            int dis = rand() % 200 + 100;
            this->vehicles.push_back(new Truck(k, y, i));
            k = this->vehicles.back()->getPos().x;
            k = k - (dis + 0.5 * vehicles[i]->GetBound().width);
        }
    }

    else if (type == OBJECT_TYPE::CAR)
    {
        int k = 0;
        for (int i = 0; i < 5; i++)
        {

            int dis = rand() % 400;
            this->vehicles.push_back(new Car(k, y));
            k = this->vehicles.back()->getPos().x;
            k = k - (dis + vehicles[i]->GetBound().width + 50);
        }
    }
}

sf::Vector2f Vehicle::getPos()
{
    sf::Vector2f a;
    return a;
}
sf::Vector2f Truck::getPos()
{
    return this->truck.getPosition();
}
sf::Vector2f Car::getPos()
{
    return this->car.getPosition();
}

void Vehicle::Render(sf::RenderWindow &window)
{
    for (auto *ani : this->vehicles)
    {
        ani->Render(window);
    }
}
void Truck::Render(sf::RenderWindow &window)
{
    window.draw(this->truck);
}
void Car::Render(sf::RenderWindow &window)
{
    window.draw(this->car);
}

void Vehicle::update(float velocity, sf::RenderWindow &window)
{
    for (int i = 0; i < 5; i++)
    {
        vehicles[i]->update(velocity, window);
        if (vehicles[i]->GetBound().left > window.getSize().x)
        {

            int k = 0;
            if (i == 0)
            {
                if (vehicles.back()->getPos().x > 0)
                {
                    k = 0 - (rand() % 300 + 100) - (velocity * 10);
                    vehicles[i]->setPos(k, vehicles[i]->getPos().y);
                }
                else
                {
                    k = vehicles.back()->getPos().x - (rand() % 300 + 100) - (velocity * 12);
                    vehicles[i]->setPos(k, vehicles[i]->getPos().y);
                }
            }
            else
            {

                k = vehicles[i - 1]->getPos().x - (rand() % 300 + 100) - (velocity * 12);
                vehicles[i]->setPos(k, vehicles[i]->getPos().y);
            }
        }
    }
}

sf::FloatRect Vehicle::GetBound()
{
    sf::FloatRect r1(0, 0, 0, 0);
    return r1;
}
sf::FloatRect Truck::GetBound()
{
    return truck.getGlobalBounds();
}
sf::FloatRect Car::GetBound()
{
    return car.getGlobalBounds();
}

void Truck::update(float velocity, sf::RenderWindow &window)
{
    this->truck.move(velocity, 0);
}
void Car::update(const float velocity, sf::RenderWindow &window)
{
    this->car.move(5.f, 0);
}
