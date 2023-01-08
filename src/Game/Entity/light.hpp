#ifndef SRC_GAME_ENTITY_LIGHT
#define SRC_GAME_ENTITY_LIGHT
#include "../../Framework/pch.hpp"

class TrafficLight
{
public:
    TrafficLight(Context &context, sf::Time delta = sf::seconds(3.f));

    void updateRed();

    void updateGreen();

    bool isRed() const;

    void draw(sf::RenderWindow &window);

    sf::Time updateTime(sf::Time dt);
    sf::Time getDelta() const;

private:
    void saveGame(std::ofstream &fout);
    void loadGame(std::ifstream &fin);
    sf::Sprite light_sprite;

    sf::Time between;

    sf::Time last_update;

    bool is_red;

    Context &m_context;

    friend class World;
};

#endif /* SRC_GAME_ENTITY_LIGHT */
