#ifndef SRC_GAME_ENTITY_PEOPLE
#define SRC_GAME_ENTITY_PEOPLE
#include "../../Framework/pch.hpp"

#include <array>
#include <chrono>
#include <math.h>

class People
{
private:
    float CELL_SIZE = 90;
    float MAP_WIDTH = 900;
    float MAP_HEIGHT = 900;
    bool dead;

    float x;
    float y;

    std::array<bool, 4> control_keys;

    sf::SoundBuffer buffer;
    sf::Sound sound;

    sf::Sprite sprite;
    sf::Texture texture;

public:
    People();
    void draw(std::shared_ptr<Context> &context);
    void set_dead();
    bool get_dead();                 // isDead()
    void playerReset();              // Reset player to the first position
    void update();                   // Control player
    void addSound(std::string link); // Add sound
    sf::IntRect get_react() const;
    // bool isImpact(const CVehicle *&car);
    // bool isImpact(const CAnimal *&animal);
    bool isFinish(); // Player win
};

#endif