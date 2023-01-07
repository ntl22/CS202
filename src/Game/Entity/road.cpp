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
    {
      roads[i] = std::make_unique<Lane>(tmp_tl, LANE_TYPE::goal, *context.textures);
    }
    else if (i == 3 || i == 6)
    {
      roads[i] = std::make_unique<Lane>(tmp_tl, LANE_TYPE::start, *context.textures);
    }
    else
    {
      if (arr[index++])
      {
        type = rand() % 2 ? OBJECT_TYPE::TRUCK : OBJECT_TYPE::CAR;
        roads[i] = std::make_unique<Lane>(tmp_tl, LANE_TYPE::street, *context.textures, type, 5, speed);
      }
      else
      {
        type = rand() % 2 ? OBJECT_TYPE::CAT : OBJECT_TYPE::CHICKEN;
        roads[i] = std::make_unique<Lane>(tmp_tl, LANE_TYPE::street, *context.textures, type, 5, speed);
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

void Road::saveGame(std::ofstream& fout) {
    for (auto& i : roads)
        i->saveGame(fout);
}

void Road::loadGame(std::ifstream& fin) {
    for (auto& i : roads)
        i->loadGame(fin);
}

void Lane::saveGame(std::ofstream& fout) {
    object->saveGame(fout);
}

void Lane::loadGame(std::ifstream& fin) {
    object->loadGame(fin);
}