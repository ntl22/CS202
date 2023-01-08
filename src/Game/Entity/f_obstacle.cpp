#include "f_obstacle.hpp"

void ListOfObstacle::saveGame(std::ofstream& fout)
{
    fout << static_cast<int>(m_type) << "\n";
    for (std::unique_ptr<Obstacle>& i : list)
        fout << i->getPos().x << " " << i->getPos().y << "\n";
}

void ListOfObstacle::loadGame(std::ifstream& fin, TextureMap& map)
{
    int type;
    fin >> type;
    m_type = static_cast<OBJECT_TYPE>(type);

    int x;
    int y;
    for (std::unique_ptr<Obstacle>& i : list)
    {
        fin >> x >> y;
        i.swap(ObstacleFactory::create(m_type, map));
        i->setPos(x, y);
    }
    fin.ignore(1000, '\n');
}

ListOfObstacle::ListOfObstacle(float position, OBJECT_TYPE type, TextureMap &map)
    : m_type(type)
{
    if (m_type == OBJECT_TYPE::NONE)
        return;
    spawnObstable(position, map);
}

void ListOfObstacle::spawnObstable(float position, TextureMap &map)
{
    size_t i = 0;
    int tmp = 1800;
    int dis;
    int padding = (m_type == OBJECT_TYPE::CAT || m_type == OBJECT_TYPE::CHICKEN) ? 50 : 0;

    for (i = 0; i < list.size(); i++)
    {
        dis = rand() % 201 + 200;

        list[i] = std::move(ObstacleFactory::create(m_type, map));
        list[i]->setPos(tmp, (int)position);
        tmp -= (int)(dis + 0.5 * list[i]->getBound().height + padding);
    }
}

void ListOfObstacle::draw(sf::RenderWindow &window)
{
    if (m_type == OBJECT_TYPE::NONE)
        return;
    for (auto &object : list)
        object->draw(window);
}

void ListOfObstacle::update(sf::Time dt, unsigned velocity, People &people,
                            TrafficLight &light, sf::RenderWindow &window)
{
    if (m_type == OBJECT_TYPE::NONE)
        return;

    size_t i, size = list.size();
    int o_width;

    unsigned w_width = window.getSize().x;

    for (i = 0; i < size; i++)
    {
        list[i]->update(dt, velocity, people, light, window);

        list[i]->collisionProcedure(people);

        if (people.getPlayingStatus() == STATUS::DEAD)
            break;

        if (list[i]->getBound().left > w_width)
        {
            size_t i_next = (i == 0 ? size - 1 : i - 1);
            sf::Vector2i next_pos(list[i_next]->getPos());
            sf::Vector2i cur_pos(list[i]->getPos());
            o_width = (int)list[i]->getBound().width;

            int dis = rand() % 201 + 200;

            if (list[i_next]->getPos().x - dis < 0)
                list[i]->setPos(next_pos.x - dis - o_width, cur_pos.y);
            else
                list[i]->setPos(-o_width, cur_pos.y);
        }
    }
}

void ListOfObstacle::handleEvent(const sf::Event &ev)
{
    if (m_type == OBJECT_TYPE::NONE)
        return;
}

OBJECT_TYPE ListOfObstacle::getType() {
    return m_type;
}
