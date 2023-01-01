#include "road.hpp"

Lane::Lane(int i, int &count)
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
        if (count >= 2)

        {
            laneBg.loadFromFile("assets/images/lane3.png");
            lane.setTexture(laneBg);
            object = new Animal();
            type = LANE_TYPE::dirt;
            lane.scale(1, 1);
            break;
        }
        else
        {
            laneBg.loadFromFile("assets/images/lane3.png");
            lane.setTexture(laneBg);
            object = new Vehicle();
            type = LANE_TYPE::street;
            lane.scale(1, 1);
            count++;
            break;
        }
    case 3:
        if (count <= 0)
        {
            laneBg.loadFromFile("assets/images/lane3.png");
            lane.setTexture(laneBg);
            object = new Vehicle();
            type = LANE_TYPE::street;
            lane.scale(1, 1);
            count++;
            break;
        }
        else
        {
            laneBg.loadFromFile("assets/images/lane3.png");
            lane.setTexture(laneBg);
            object = new Animal();
            type = LANE_TYPE::dirt;
            lane.scale(1, 1);
            break;
        }
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
    int count = 0;
    lightRed.loadFromFile("assets/images/lightRed.png");
    lightGreen.loadFromFile("assets/images/lightGreen.png");
    light.setTexture(lightGreen);
    roads.push_back(new Lane(1, count));
    for (int i = 0; i < 2; i++)
    {
        int tmp = rand() % 2 + 2;
        roads.push_back(new Lane(tmp, count));
    }
    roads.push_back(new Lane(1, count));
    for (int i = 0; i < 2; i++)
    {
        int tmp = rand() % 2 + 2;
        roads.push_back(new Lane(tmp, count));
    }
    roads.push_back(new Lane(4, count));
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
            this->object->spawn(lane.getPosition().y - 5 + this->lane.getGlobalBounds().height / 4, OBJECT_TYPE::TRUCK);
        }
        else
            this->object->spawn(lane.getPosition().y - 5 + this->lane.getGlobalBounds().height / 4, OBJECT_TYPE::CAR);
    }
    else if (type == LANE_TYPE::dirt)
    {
        int ran = rand() % 2 + 1;
        if (ran == 1)
        {
            this->object->spawn(lane.getPosition().y - 5 + this->lane.getGlobalBounds().height / 4, OBJECT_TYPE::CAT);
        }
        else
            this->object->spawn(lane.getPosition().y - 5 + this->lane.getGlobalBounds().height / 4, OBJECT_TYPE::CHICKEN);
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
void Lane::update(const float velocity, sf::RenderWindow &window, People &people)
{

    if ((type == LANE_TYPE::street) || (type == LANE_TYPE::dirt))
    {
        object->update(velocity, window, people);
    }
}
void Road::update(const float velocity, sf::RenderWindow &window, People &people)
{
    // int ran = rand() % 5 + 1;

    // sf::Clock clock;
    // sf::Time time1 = clock.getElapsedTime();
    // if (tmp == ran)
    // {
    //     if (checkLight == true)
    //         checkLight == false;
    //     else
    //         checkLight = true;
    // }

    // updateLight();
    if (this->checkLight)
    {
        for (int i = 1; i < 6; i++)
        {

            this->roads[i]->update(velocity, window, people);
        }
    }
    // time1 = clock.restart();
}
void Road::updateLight()
{

    if (checkLight == true)
    {
        light.setTexture(lightGreen);
    }
    else
        light.setTexture(lightRed);
}
void Road::drawRoad(sf::RenderWindow &window)
{
    // light.setPosition(window.getSize().x, 0);
    this->roads[0]->drawRoad(window);
    for (int i = 1; i < 6; i++)
    {
        this->roads[i]->drawRoad(window);
    }
    this->roads[6]->drawRoad(window);
    light.setPosition(window.getSize().x - light.getGlobalBounds().width - 20, 5);
    window.draw(light);
}
