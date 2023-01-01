#ifndef SRC_GAME_ENTITY_PEOPLE
#define SRC_GAME_ENTITY_PEOPLE
#include "../../Framework/pch.hpp"

#include <array>
#include <chrono>
#include <math.h>

class People
{
private:
    float CELL_WIDTH;
    float CELL_HEIGHT;
    const float MAP_WIDTH;
    const float MAP_HEIGHT;
    bool dead;
    int direction;

    float x;
    float y;

    std::array<bool, 4> control_keys;

    sf::SoundBuffer buffer;
    sf::Sound sound;

    sf::Sprite sprite;
    sf::Texture texture;

    AssetMap<TEXTURES, sf::Texture>& m_textures;

public:
    People(sf::RenderWindow& window, AssetMap<TEXTURES, sf::Texture>& textures);
    void createTexture();

    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& ev);                   // Control player
    void update(sf::Time dt);
    
    void set_dead();
    bool get_dead();                 // isDead()
    void playerReset();              // Reset player to the first position
    void addSound(std::string link); // Add sound
    sf::FloatRect get_react() const;
    bool isFinish(); // Player win
};

#endif /* SRC_GAME_ENTITY_PEOPLE */
