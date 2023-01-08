#ifndef SRC_GAME_ENTITY_F_OBSTACLE
#define SRC_GAME_ENTITY_F_OBSTACLE
#include "../../Framework/pch.hpp"

#include "obstacle.hpp"
#include "animal.hpp"
#include "vehicle.hpp"
#include "player.hpp"

class ObstacleFactory
{
public:
    static std::unique_ptr<Obstacle> create(OBJECT_TYPE type, TextureMap &map)
    {
        Obstacle *raw_ptr;

        switch (type)
        {
        case OBJECT_TYPE::CAR:
            raw_ptr = new Car(map);
            break;
        case OBJECT_TYPE::TRUCK:
            raw_ptr = new Truck(map);
            break;
        case OBJECT_TYPE::CAT:
            raw_ptr = new Cat(map);
            break;
        case OBJECT_TYPE::CHICKEN:
            raw_ptr = new Chicken(map);
            break;
        default:
            throw std::runtime_error("ObstacleFactory::ObstacleFactory() : invalid type");
        }

        return std::unique_ptr<Obstacle>(std::move(raw_ptr));
    }
};
class ListOfObstacle
{
private:
    std::array<std::unique_ptr<Obstacle>, 5> list;

    void spawnObstable() {}

    OBJECT_TYPE m_type;

    void spawnObstable(float position, TextureMap &map);

public:
    ListOfObstacle(float position, OBJECT_TYPE type, TextureMap &map);

    void draw(sf::RenderWindow &window);
    void update(sf::Time dt, unsigned velocity, People &people,
                TrafficLight &light, sf::RenderWindow &window);
    void handleEvent(const sf::Event &ev);
    OBJECT_TYPE getType();

    void saveGame(std::ofstream &fout);
    void loadGame(std::ifstream &fin, TextureMap &map);
};

#endif /* SRC_GAME_ENTITY_F_OBSTACLE */
