#include "people.hpp"

template <class T>
const T &clamp(const T &x, const T &upper, const T &lower)
{
    return fmin(upper, fmax(x, lower));
}

People::People(sf::RenderWindow &window)
    : MAP_WIDTH(window.getSize().x * 1.f),
      MAP_HEIGHT(window.getSize().y * 1.f)
{
    playerReset();
}

void People::createTexture()
{
    if (texture.loadFromFile("./assets/images/player1.png"))
        std::cout << "Draw People fail";
    // sprite.setTexture(context->textures->get(TEXTURES::player));
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(x, y));
    sprite.setScale(sf::Vector2f(CELL_WIDTH / (float)52, CELL_HEIGHT / (float)95));
}

void People::draw(sf::RenderWindow &window)
{
    createTexture();
    window.draw(sprite);
}

void People::set_dead()
{
    dead = 1;
}

bool People::get_dead() // isDead()
{
    return dead;
}

void People::playerReset()
{
    dead = 0;

    CELL_HEIGHT = MAP_HEIGHT / 6;
    CELL_WIDTH = CELL_HEIGHT * 52 / 95;

    x = (MAP_WIDTH - CELL_WIDTH) / 2;
    y = MAP_HEIGHT - CELL_HEIGHT;

    control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

void People::handleEvent(const sf::Event &ev)
{
    bool moved = 0;

    if (0 == control_keys[0] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        moved = 1;

        x = std::min(CELL_WIDTH + x, (float)MAP_WIDTH - CELL_WIDTH);
    }
    else if (0 == control_keys[1] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        moved = 1;

        y = std::max(y - CELL_HEIGHT, (float)0);
    }
    else if (0 == control_keys[2] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        moved = 1;

        x = std::max(x - CELL_WIDTH, (float)0);
    }
    else if (0 == control_keys[3] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        moved = 1;

        y = std::min(CELL_HEIGHT + y, (float)MAP_HEIGHT - CELL_HEIGHT);
    }

    control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    // if (1 == moved)
    //{
    //     addSound("./assets/sounds/jump.wav");
    // }
}

void People::update(sf::Time dt) {}

void People::addSound(std::string link)
{
    buffer.loadFromFile(link);
    sound.setBuffer(buffer);
    sound.setLoop(false);
    sound.play();
}

sf::IntRect People::get_react() const
{
    return sf::IntRect(x, y, CELL_WIDTH, CELL_HEIGHT);
}

// bool People::isImpact(const CVehicle *&car)
// {
//     if (0 == dead)
//     {
//         if (1 == car.get_react().intersects(get_react()))
//         {
//             return true;
//             // or setDead();
//         }
//     }
// }

// bool People::isImpact(const CAnimal *&animal)
// {
//     if (0 == dead)
//     {
//         if (1 == animal.get_react().intersects(get_react()))
//         {
//             return true;
//             // or setDead();
//         }
//     }
// }

bool People::isFinish()
{
    if (y == 1)
        return true;
    return false;
}