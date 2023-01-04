#include "road.hpp"

Lane::Lane(float position,
           LANE_TYPE type,
           TextureMap &map,
           OBJECT_TYPE animal,
           unsigned num,
           unsigned speed,
           Lane::DIRRECTION dirrection)
    : DEFAULT_NUM(num),
      m_type(animal),
      DEFAULT_SPEED(speed)
{
  switch (type)
  {
  case LANE_TYPE::goal:
    roadBg = map.get(TEXTURES::lane4);
    break;
  case LANE_TYPE::street:
    roadBg = map.get(TEXTURES::lane3);
    break;
  case LANE_TYPE::start:
    roadBg = map.get(TEXTURES::lane1);
    break;
  }

  road.setTexture(roadBg);
  road.setPosition({0, position});

  object = std::make_unique<ListOfObstacle>(road.getPosition().y - 5 + this->road.getGlobalBounds().height / 4,
                                            num, animal, map);
}

void Lane::draw(sf::RenderWindow &window)
{
  window.draw(road);
  object->draw(window);
}

void Lane::update(sf::Time dt,
                  People &people,
                  TrafficLight &light,
                  sf::RenderWindow &window)
{
  bool condition = light.isRed() && ((m_type == OBJECT_TYPE::CAR) || (m_type == OBJECT_TYPE::TRUCK));

  object->update(dt, condition ? 0 : DEFAULT_SPEED, people, window);
}

float Lane::getBound()
{
  return road.getGlobalBounds().height;
}

OBJECT_TYPE Lane::getType()
{
  return m_type;
}

Road::Road(Context &context)
    : roads(7), collied(OBJECT_TYPE::NONE)
{
  unsigned animals = rand() % 3 + 1;
  unsigned vehicles = 4 - animals;

  size_t i = 0;
  int selection;
  bool finish;
  OBJECT_TYPE type;

  float tmp_tl = 0;

  while (i < 7)
  {
    if (i == 0)
    {
      roads[i] = std::make_unique<Lane>(tmp_tl, LANE_TYPE::goal, *context.textures);
    }
    else if (i == 3 || i == 6)
    {
      roads[i] = std::make_unique<Lane>(tmp_tl, LANE_TYPE::start, *context.textures);
    }
    else
    {
      finish = false;
      while (!finish)
      {
        selection = rand() % 2;
        if (selection && vehicles)
        {
          type = rand() % 2 ? OBJECT_TYPE::TRUCK : OBJECT_TYPE::CAT;
          roads[i] = std::make_unique<Lane>(tmp_tl, LANE_TYPE::street, *context.textures, type);
          --vehicles;
          finish = true;
        }
        else
        {
          type = rand() % 2 ? OBJECT_TYPE::CAT : OBJECT_TYPE::CHICKEN;
          roads[i] = std::make_unique<Lane>(tmp_tl, LANE_TYPE::street, *context.textures, type);
          --vehicles;
          finish = true;
        }
      }
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
      collied = r->getType();
  }
}

OBJECT_TYPE Road::getType()
{
  return collied;
}
