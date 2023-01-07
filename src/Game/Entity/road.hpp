#ifndef SRC_GAME_ENTITY_ROAD
#define SRC_GAME_ENTITY_ROAD
#include "collidable.hpp"

#include "light.hpp"
#include "player.hpp"

class Lane
{
public:
    enum class DIRRECTION
    {
        LEFT,
        RIGHT
    };

    Lane() = default;

    virtual ~Lane() = default;

    Lane(float position,
         LANE_TYPE type,
         TextureMap &map,
         OBJECT_TYPE animal = OBJECT_TYPE::NONE,
         unsigned num = 5,
         unsigned speed = 5,
         Lane::DIRRECTION dirrection = DIRRECTION::LEFT);

    virtual void draw(sf::RenderWindow &window);

    virtual void update(sf::Time dt,
                        People &people,
                        TrafficLight &light,
                        sf::RenderWindow &window);

    float getBound();

    virtual OBJECT_TYPE getType();

private:
    void saveGame(std::ofstream& fout);
    void loadGame(std::ifstream& fin);
    sf::Sprite road;
    sf::Texture roadBg;
    std::unique_ptr<ListOfObstacle> object;
    OBJECT_TYPE m_type;

    const unsigned DEFAULT_NUM, DEFAULT_SPEED;

    friend class Road;
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
    void saveGame(std::ofstream& fout);
    void loadGame(std::ifstream& fin);
    std::array<std::unique_ptr<Lane>, 7> roads;

    OBJECT_TYPE collied;

    friend class World;
};

#endif /* SRC_GAME_ENTITY_ROAD */
