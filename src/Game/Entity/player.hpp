#ifndef SRC_GAME_ENTITY_PLAYER
#define SRC_GAME_ENTITY_PLAYER
#include "obstacle.hpp"

enum class STATUS
{
    WIN,
    DEAD,
    PLAYING
};

class People
{
public:
    People(Context &context);

    virtual ~People() = default;

    void draw(sf::RenderWindow &window);

    void update(sf::Time dt);

    void handleEvent(const sf::Event &ev);

    STATUS getPlayingStatus() const;

    sf::FloatRect getReact() const;

    bool isLeft() const;
    bool isRight() const;
    bool isUp() const;
    bool isDown() const;

private:
    void saveGame(std::ofstream &fout);
    void loadGame(std::ifstream &fin);

    void createTexture();

    std::array<bool, 4> control_keys;

    const float MAP_WIDTH, MAP_HEIGHT;
    float CELL_WIDTH, CELL_HEIGHT;

    short direction;

    sf::Vector2f position;

    TextureMap &m_textures;
    SoundManager &m_sound;
    sf::Sprite sprite;

    STATUS status;

    friend class Lane;
    friend class Obstacle;

    friend class World;
};

#endif /* SRC_GAME_ENTITY_PLAYER */
