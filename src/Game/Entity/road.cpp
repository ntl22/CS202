#include "road.hpp"

Lane::Lane(float position, sf::Texture &roadBg)
{
    road.setTexture(roadBg);
    road.setPosition({0, position});
}

void Lane::draw(sf::RenderWindow &window)
{
    window.draw(road);
}

void Lane::update(sf::Time dt,
                  People &people,
                  TrafficLight &light,
                  sf::RenderWindow &window) {}

float Lane::getBound() { return road.getGlobalBounds().height; }

OBJECT_TYPE Lane::getType() { return OBJECT_TYPE::NONE; }

ObstacleLane::ObstacleLane(float position,
                           TextureMap &map,
                           OBJECT_TYPE type,
                           unsigned speed)
    : Lane(position, map.get(TEXTURES::lane3)), m_speed(speed)
{
    float relative = road.getPosition().y - 5 + this->road.getGlobalBounds().height / 4;
    object = std::make_unique<ListOfObstacle>(relative, type, map);
    m_type = type;
}

OBJECT_TYPE ObstacleLane::getType() {
    return object->getType();
}

void ObstacleLane::draw(sf::RenderWindow &window)
{
    Lane::draw(window);
    object->draw(window);
}

void ObstacleLane::update(sf::Time dt,
                          People &people,
                          TrafficLight &light,
                          sf::RenderWindow &window)
{
    object->update(dt, m_speed, people, light, window);
}

void ObstacleLane::saveGame(std::ofstream& fout)
{
    object->saveGame(fout);
}

void ObstacleLane::loadGame(std::ifstream& fin, TextureMap& map)
{
    object->loadGame(fin, map);
}

Road::Road(Context &context, unsigned speed)
    : collied(OBJECT_TYPE::NONE)
{
    unsigned animals = rand() % 3 + 1;

    bool arr[4] = {0};

    while (animals)
    {
        int index = rand() % 4;
        if (!arr[index])
        {
            arr[index] = 1;
            animals--;
        }
    }

    size_t i = 0;
    OBJECT_TYPE type;
    int index = 0;
    float tmp_tl = 0;

    while (i < 7)
    {
        if (i == 0)
            roads[i] = LaneFactory::createLane(tmp_tl, *context.textures, LANE_TYPE::goal);
        else if (i == 3 || i == 6)
            roads[i] = LaneFactory::createLane(tmp_tl, *context.textures, LANE_TYPE::grass);
        else
        {
            if (arr[index++])
                type = rand() % 2 ? OBJECT_TYPE::TRUCK : OBJECT_TYPE::CAR;
            else
                type = rand() % 2 ? OBJECT_TYPE::CAT : OBJECT_TYPE::CHICKEN;
            roads[i] = LaneFactory::createLane(tmp_tl, *context.textures, LANE_TYPE::street, type, speed);
        }
        tmp_tl += roads[i++]->getBound();
    }
}

void Road::draw(sf::RenderWindow &window)
{
    for (auto &r : roads)
        r->draw(window);
}

void Road::update(sf::Time dt,
                  People &people,
                  TrafficLight &light,
                  sf::RenderWindow &window)
{
    for (auto &r : roads)
    {
        r->update(dt, people, light, window);
        if (people.getPlayingStatus() == STATUS::DEAD)
        {
            collied = r->getType();
            break;
        }
    }
}

OBJECT_TYPE Road::getType()
{
    return collied;
}

void Road::saveGame(std::ofstream& fout)
{
    for (auto& i : roads)
        i->saveGame(fout);
}

void Road::loadGame(std::ifstream& fin, TextureMap& map)
{
    for (auto& i : roads)
        i->loadGame(fin, map);
}
