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

public:
    People(sf::RenderWindow& window);
    void createTexture();

    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& ev);                   // Control player
    void update(sf::Time dt);
    
    void set_dead();
    bool get_dead();                 // isDead()
    void playerReset();              // Reset player to the first position
    void addSound(std::string link); // Add sound
    sf::IntRect get_react() const;
    // bool isImpact(const CVehicle *&car);
    // bool isImpact(const CAnimal *&animal);
    bool isFinish(); // Player win
};

#endif /* SRC_GAME_ENTITY_PEOPLE */
