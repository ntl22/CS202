#include "people.hpp"

template<class T>
const T& clamp(const T& x, const T& upper, const T& lower) {
    return fmin(upper, fmax(x, lower));
}

People::People()
{
    playerReset();
}

void People::draw(std::shared_ptr<Context>& context)
{
    if (0 == dead)
    {
        //texture.loadFromFile("./assets/images/player.png");
        sprite.setTexture(context->textures->get(TEXTURES::player));
    }

    //sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(x, y));
    sprite.setScale(sf::Vector2f(CELL_SIZE / (float)210, CELL_SIZE / (float)209));

    context->window->draw(sprite);
}

void People::set_dead()
{
    if (0 == dead)
    {
        dead = 1;
    }
}

bool People::get_dead() // isDead()
{
    return dead;
}

void People::playerReset() {
    dead = 0;

    x = (MAP_WIDTH - CELL_SIZE) / 2;
    y = MAP_HEIGHT - CELL_SIZE;

    control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

void People::update()
{
    if (0 == dead)
    {
        bool moved = 0;

        if (0 == control_keys[0] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            moved = 1;

            x = std::min(CELL_SIZE + x, (float)MAP_WIDTH - CELL_SIZE);
        }
        else if (0 == control_keys[1] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            moved = 1;

            y = std::max(y - CELL_SIZE, (float)0);
        }
        else if (0 == control_keys[2] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            moved = 1;

            x = std::max(x - CELL_SIZE, (float)0);
        }
        else if (0 == control_keys[3] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            moved = 1;

            y = std::min(CELL_SIZE + y, (float)MAP_HEIGHT - CELL_SIZE);
        }

        control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

        if (1 == moved)
        {
            addSound("./assets/sounds/jump.wav");
        }

    }
}


void People::addSound(std::string link) {
    buffer.loadFromFile(link);
    sound.setBuffer(buffer);
    sound.setLoop(false);
    sound.play();
}

sf::IntRect People::get_react() const
{
    return sf::IntRect(x, y, CELL_SIZE, CELL_SIZE);
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
