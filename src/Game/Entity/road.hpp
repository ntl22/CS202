#ifndef SRC_GAME_ENTITY_ROAD
#define SRC_GAME_ENTITY_ROAD
#include "f_obstacle.hpp"
#include "f_road.hpp"
#include "light.hpp"
#include "player.hpp"

class Lane
{
public:
    virtual ~Lane() = default;

    Lane(float position, sf::Texture &roadBg);

    virtual void draw(sf::RenderWindow &window);

    virtual void update(sf::Time dt,
                        People &people,
                        TrafficLight &light,
                        sf::RenderWindow &window);

    float getBound();

    virtual OBJECT_TYPE getType();

     virtual void saveGame(std::ofstream &fout) {}
     virtual void loadGame(std::ifstream &fin, TextureMap &map) {}

protected:
    sf::Sprite road;
};

class GoalLane : public Lane
{
public:
    GoalLane(float position, TextureMap &map)
        : Lane(position, map.get(TEXTURES::lane4)) {}
};

class GrassLane : public Lane
{
public:
    GrassLane(float position, TextureMap &map)
        : Lane(position, map.get(TEXTURES::lane1)) {}
};

class ObstacleLane : public Lane
{
public:
    ObstacleLane(float position,
                 TextureMap &map,
                 OBJECT_TYPE type,
                 unsigned speed);

    OBJECT_TYPE getType();

    void draw(sf::RenderWindow &window) override;

    void update(sf::Time dt,
                People &people,
                TrafficLight &light,
                sf::RenderWindow &window) override;

     void saveGame(std::ofstream &fout) override;

     void loadGame(std::ifstream &fin, TextureMap &map) override;

private:
    std::unique_ptr<ListOfObstacle> object;
    OBJECT_TYPE m_type;
    const unsigned m_speed;
};

class Road
{
public:
    Road(Context &context, unsigned speed);

    void draw(sf::RenderWindow &window);

    void update(sf::Time dt,
                People &people,
                TrafficLight &light,
                sf::RenderWindow &window);

    OBJECT_TYPE getType();

private:
    void saveGame(std::ofstream &fout);
    void loadGame(std::ifstream &fin, TextureMap &map);
    std::array<std::unique_ptr<Lane>, 7> roads;

    OBJECT_TYPE collied;

    friend class World;
};
#endif /* SRC_GAME_ENTITY_ROAD */
