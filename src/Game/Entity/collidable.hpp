#ifndef SRC_GAME_ENTITY_COLLIDABLE
#define SRC_GAME_ENTITY_COLLIDABLE
#include "../../Framework/pch.hpp"

#include "player.hpp"

enum class LANE_TYPE
{
    goal,
    start,
    dirt,
    street
};

class People;

class Obstacle
{
public:
    virtual ~Obstacle() = default;

    virtual void draw(sf::RenderWindow &window) = 0;
    virtual void update(sf::Time dt, unsigned velocity, People &people, sf::RenderWindow &window) = 0;
    virtual void handleEvent(const sf::Event &ev) = 0;
    virtual sf::FloatRect getBound() = 0;
    virtual sf::Vector2f getPos() = 0;
    virtual void setPos(int x, int y) = 0;
    void collisionProcedure(People &people);
};

class Animal : public Obstacle
{
public:
    Animal(OBJECT_TYPE type, TextureMap &map);

    void draw(sf::RenderWindow &window);
    void update(sf::Time dt, unsigned velocity, People &people, sf::RenderWindow &window);
    sf::FloatRect getBound();
    void setPos(int x, int y);
    sf::Vector2f getPos();
    void handleEvent(const sf::Event &ev) {}

private:
    sf::Sprite animal;
    sf::Texture animalTex;
};

class Vehicle : public Obstacle
{
public:
    Vehicle(OBJECT_TYPE type, TextureMap &map);

    void draw(sf::RenderWindow &window);
    void update(sf::Time dt, unsigned velocity, People &people, sf::RenderWindow &window);
    sf::Vector2f getPos();
    void setPos(int x, int y);
    void handleEvent(const sf::Event &ev) {}
    sf::FloatRect getBound();

private:
    sf::Sprite vehicle;
    sf::Texture vehicleTex;
};

class ListOfObstacle : public Obstacle
{
private:
    std::vector<std::unique_ptr<Obstacle>> list;

    void spawnObstable() {}

    OBJECT_TYPE m_type;

    sf::Vector2f getPos() { return {0.f, 0.f}; }

    void setPos(int x, int y) {}

    sf::FloatRect getBound() { return {0.f, 0.f, 0.f, 0.f}; }

public:
    void saveGame(std::ofstream& fout);
    void loadGame(std::ifstream& fin);

    ListOfObstacle(float position, unsigned num, OBJECT_TYPE type, TextureMap &map)
        : list(type != OBJECT_TYPE::NONE ? num : 0), m_type(type)
    {
        spawnObstable(position, type, map);
    }

    void spawnObstable(float position, OBJECT_TYPE type, TextureMap &map)
    {
        size_t i = 0;
        int tmp = 0;
        int dis = 0;
        switch (type)
        {
        case OBJECT_TYPE::CAT:
            for (i = 0; i < list.size(); i++)
            {
                dis = rand() % 200 + 150;

                list[i] = std::make_unique<Animal>(type, map);
                list[i]->setPos(tmp, (int)position);
                tmp -= (int)(dis + 0.5 * list[i]->getBound().height + 50);
            }
            break;
        case OBJECT_TYPE::CHICKEN:
            for (i = 0; i < list.size(); i++)
            {
                dis = rand() % 200 + 150;

                list[i] = std::make_unique<Animal>(type, map);
                list[i]->setPos(tmp, (int)position);
                tmp -= (int)(dis + 0.5 * list[i]->getBound().height + 50);
            }
            break;
        case OBJECT_TYPE::CAR:
            for (i = 0; i < list.size(); i++)
            {
                int dis = rand() % 200 + 150;
                list[i] = std::make_unique<Vehicle>(type, map);
                list[i]->setPos(tmp, (int)position);
                tmp -= (int)(dis + 0.5 * list[i]->getBound().height);
            }
            break;
        case OBJECT_TYPE::TRUCK:
            for (i = 0; i < list.size(); i++)
            {
                int dis = rand() % 200 + 150;
                list[i] = std::make_unique<Vehicle>(type, map);
                list[i]->setPos(tmp, (int)position);
                tmp -= (int)(dis + 0.5 * list[i]->getBound().height);
            }
            break;
        default:
            break;
        }
    }

    void draw(sf::RenderWindow &window)
    {
        for (auto &object : list)
            object->draw(window);
    }

    void update(sf::Time dt, unsigned velocity, People &people, sf::RenderWindow &window);

    void handleEvent(const sf::Event &ev)
    {
        for (auto &object : list)
            object->handleEvent(ev);
    }
};

#endif /* SRC_GAME_ENTITY_COLLIDABLE */
