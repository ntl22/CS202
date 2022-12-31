#include "animal.hpp"

void Animal::setPos(int x, int y)
{
    return;
}
void Cat::setPos(int x, int y)
{
    this->cat.setPosition(x, y);
}
void Dog::setPos(int x, int y)
{
    this->dog.setPosition(x, y);
}

void Cat::innitTexture(int i)
{
    int t = rand() % 2 + 1;

    if (catTexture.loadFromFile("assets/images/cat" + std::to_string(i) + ".png"))
    {
        std::cout << "Fail texture";
    }
    this->cat.setTexture(catTexture);
    cat.scale(1.5, 1.5);
}
void Dog::innitTexture()
{
    if (dogTexture.loadFromFile("assets/images/chicken.png"))
    {
        std::cout << "Fail texture";
    }
    this->dog.setTexture(dogTexture);
    dog.scale(1.5, 1.5);
}

void Animal::spawn(float y, const OBJECT_TYPE type)
{
    if (type == OBJECT_TYPE::CAT)
    {
        int k = 0;
        for (int i = 0; i < 5; i++)
        {

            int dis = rand() % 200 + 100;
            this->animals.push_back(new Cat(k, y, i));
            k = this->animals.back()->getPos().x;
            k = k - (dis + 0.5 * animals[i]->GetBound().width);
        }
    }

    else if (type == OBJECT_TYPE::CHICKEN)
    {
        int k = 0;
        for (int i = 0; i < 5; i++)
        {

            int dis = rand() % 400;
            this->animals.push_back(new Dog(k, y));
            k = this->animals.back()->getPos().x;
            k = k - (dis + animals[i]->GetBound().width + 50);
        }
    }
}

sf::Vector2f Animal::getPos()
{
    sf::Vector2f a;
    return a;
}
sf::Vector2f Cat::getPos()
{
    return this->cat.getPosition();
}
sf::Vector2f Dog::getPos()
{
    return this->dog.getPosition();
}

void Animal::Render(sf::RenderWindow &window)
{
    for (auto *ani : this->animals)
    {
        ani->Render(window);
    }
}
void Cat::Render(sf::RenderWindow &window)
{
    window.draw(this->cat);
}
void Dog::Render(sf::RenderWindow &window)
{
    window.draw(this->dog);
}

void Animal::update(float velocity, sf::RenderWindow &window)
{
    for (int i = 0; i < 5; i++)
    {
        animals[i]->update(velocity, window);
        if (animals[i]->GetBound().left > window.getSize().x)
        {

            int k = 0;
            if (i == 0)
            {
                if (animals.back()->getPos().x > 0)
                {
                    k = 0 - (rand() % 300 + 00) - (velocity * 12);
                    animals[i]->setPos(k, animals[i]->getPos().y);
                }
                else
                {
                    k = animals.back()->getPos().x - (rand() % 300 + 100) - (velocity * 12);
                    animals[i]->setPos(k, animals[i]->getPos().y);
                }
            }
            else
            {

                k = animals[i - 1]->getPos().x - (rand() % 300 + 100) - (velocity * 12);
                animals[i]->setPos(k, animals[i]->getPos().y);
            }
        }
    }
}

sf::FloatRect Animal::GetBound()
{
    sf::FloatRect r1(0, 0, 0, 0);
    return r1;
}
sf::FloatRect Cat::GetBound()
{
    return cat.getGlobalBounds();
}
sf::FloatRect Dog::GetBound()
{
    return dog.getGlobalBounds();
}

void Cat::update(float velocity, sf::RenderWindow &window)
{
    this->cat.move(velocity, 0);
}
void Dog::update(const float velocity, sf::RenderWindow &window)
{
    this->dog.move(5.f, 0);
}
