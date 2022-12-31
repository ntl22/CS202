#include "road.hpp"

Lane::Lane(int i)
{
    switch (i)
    {
    case 1:
        laneBg.loadFromFile("assets/images/lane1.png");
        lane.setTexture(laneBg);
        object = new Animal();
        type = LANE_TYPE::start;
        lane.scale(1, 1);
        break;

    case 2:
        laneBg.loadFromFile("assets/images/lane2.png");
        lane.setTexture(laneBg);

        object = new Vehicle();
        type = LANE_TYPE::street;
        lane.scale(1, 1);
        break;
    case 3:
        laneBg.loadFromFile("assets/images/lane3.png");
        lane.setTexture(laneBg);
        object = new Animal();
        type = LANE_TYPE::dirt;
        lane.scale(1, 1);
        break;
    case 4:
        laneBg.loadFromFile("assets/images/lane4.png");
        lane.setTexture(laneBg);
        object = new Animal();
        type = LANE_TYPE::goal;
        lane.scale(1, 1);
        break;
    }
}
void Road::LoadLane()
{

    roads.push_back(new Lane(1));
    for (int i = 0; i < 5; i++)
    {
        int tmp = rand() % 2 + 2;
        roads.push_back(new Lane(tmp));
    }
    roads.push_back(new Lane(4));
}
float Road::getBound()
{
    return 0;
}
float Lane::getBound()
{
    return lane.getGlobalBounds().height;
}
void Lane::setPos(int y, sf::RenderWindow &window)
{
    this->lane.setPosition(0, y);
    if (type == LANE_TYPE::street)
    {
        int ran = rand() % 2 + 1;
        if (ran == 1)
        {
            this->object->spawn(lane.getPosition().y + this->lane.getGlobalBounds().height / 4, OBJECT_TYPE::TRUCK);
        }
        else
            this->object->spawn(lane.getPosition().y + this->lane.getGlobalBounds().height / 4, OBJECT_TYPE::CAR);
    }
    else if (type == LANE_TYPE::dirt)
    {
        int ran = rand() % 2 + 1;
        if (ran == 1)
        {
            this->object->spawn(lane.getPosition().y + this->lane.getGlobalBounds().height / 4, OBJECT_TYPE::CAT);
        }
        else
            this->object->spawn(lane.getPosition().y + this->lane.getGlobalBounds().height / 4, OBJECT_TYPE::CHICKEN);
    }
}
void Road::setPos(int y, sf::RenderWindow &window)
{
    this->roads[6]->setPos(0, window);
    int k = 0;
    for (int i = 5; i >= 0; i--)
    {
        k += roads[i + 1]->getBound();
        this->roads[i]->setPos(k, window);
    }
}
void Lane::drawRoad(sf::RenderWindow &window)
{
    window.draw(this->lane);
    object->Render(window);
}
void Lane::update(const float velocity, sf::RenderWindow &window)
{

    object->update(velocity, window);
}
void Road::update(const float velocity, sf::RenderWindow &window)
{

    for (int i = 1; i < 6; i++)
    {
        this->roads[i]->update(velocity, window);
    }
}

void Road::drawRoad(sf::RenderWindow &window)
{
    this->roads[0]->drawRoad(window);
    for (int i = 1; i < 6; i++)
    {
        this->roads[i]->drawRoad(window);
    }
    this->roads[6]->drawRoad(window);
}